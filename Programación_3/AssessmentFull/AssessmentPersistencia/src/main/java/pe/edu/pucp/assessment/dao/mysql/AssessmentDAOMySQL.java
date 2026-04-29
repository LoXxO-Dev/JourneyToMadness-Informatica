package pe.edu.pucp.assessment.dao.mysql;

import pe.edu.pucp.assessment.dao.AssessmentDAO;
import pe.edu.pucp.assessment.db.DBFactoryProvider;
import pe.edu.pucp.assessment.model.Assessment;
import pe.edu.pucp.assessment.model.AssessmentItem;
import pe.edu.pucp.assessment.model.Teacher;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

public class AssessmentDAOMySQL implements AssessmentDAO {

    @Override
    public Integer insertar(Assessment assessment, Connection connection) throws Exception {
        // 1. Insertar assessment principal
        String sqlAssessment = "INSERT INTO assessment (duration_in_minutes, start_date) VALUES (?, ?)";
        try (PreparedStatement ps = connection.prepareStatement(sqlAssessment, Statement.RETURN_GENERATED_KEYS)) {
            ps.setInt(1, assessment.getDurationInMinutes());
            ps.setTimestamp(2, new java.sql.Timestamp(assessment.getStartDate().getTime()));
            ps.executeUpdate();
            try (ResultSet rs = ps.getGeneratedKeys()) {
                if (rs.next()) {
                    assessment.setId(rs.getInt(1));
                }
            }
        }

        // 2. Insertar relacion assessment - teacher
        String sqlTeacher = "INSERT INTO assessment_teacher (assessment_id, teacher_id) VALUES (?, ?)";
        try (PreparedStatement ps = connection.prepareStatement(sqlTeacher)) {
            for (Teacher teacher : assessment.getTeachers()) {
                ps.setInt(1, assessment.getId());
                ps.setInt(2, teacher.getId());
                ps.addBatch();
            }
            ps.executeBatch();
        }

        // 3. Insertar assessment items
        String sqlItem = "INSERT INTO assessment_item (assessment_id, question_id, score) VALUES (?, ?, ?)";
        try (PreparedStatement ps = connection.prepareStatement(sqlItem, Statement.RETURN_GENERATED_KEYS)) {
            for (AssessmentItem item : assessment.getAssessmentItems()) {
                ps.setInt(1, assessment.getId());
                ps.setInt(2, item.getQuestion().getId());
                ps.setDouble(3, item.getScore());
                ps.executeUpdate();
                try (ResultSet rs = ps.getGeneratedKeys()) {
                    if (rs.next()) {
                        item.setId(rs.getInt(1));
                    }
                }
            }
        }

        return assessment.getId();
    }

    @Override
    public void actualizar(Assessment assessment, Connection connection) throws Exception {
        String sql = "UPDATE assessment SET duration_in_minutes=?, start_date=? WHERE id=?";
        try (PreparedStatement ps = connection.prepareStatement(sql)) {
            ps.setInt(1, assessment.getDurationInMinutes());
            ps.setTimestamp(2, new java.sql.Timestamp(assessment.getStartDate().getTime()));
            ps.setInt(3, assessment.getId());
            ps.executeUpdate();
        }
    }

    @Override
    public void eliminar(Integer id, Connection connection) throws Exception {
        try (PreparedStatement ps = connection.prepareStatement(
                "DELETE FROM assessment_item WHERE assessment_id=?")) {
            ps.setInt(1, id);
            ps.executeUpdate();
        }
        try (PreparedStatement ps = connection.prepareStatement(
                "DELETE FROM assessment_teacher WHERE assessment_id=?")) {
            ps.setInt(1, id);
            ps.executeUpdate();
        }
        try (PreparedStatement ps = connection.prepareStatement(
                "DELETE FROM assessment WHERE id=?")) {
            ps.setInt(1, id);
            ps.executeUpdate();
        }
    }

    @Override
    public Assessment obtenerPorId(Integer id) throws Exception {
        String sql = "SELECT id, duration_in_minutes, start_date FROM assessment WHERE id=?";
        Assessment assessment = null;
        try (Connection conn = DBFactoryProvider.getManager().getConnection();
             PreparedStatement ps = conn.prepareStatement(sql)) {
            ps.setInt(1, id);
            try (ResultSet rs = ps.executeQuery()) {
                if (rs.next()) {
                    assessment = mapearResultSet(rs);
                }
            }
            if (assessment == null) return null;

            // Cargar teachers
            String sqlTeachers = "SELECT t.id, t.pucp_code, t.first_name, t.last_name "
                    + "FROM teacher t "
                    + "JOIN assessment_teacher at2 ON t.id = at2.teacher_id "
                    + "WHERE at2.assessment_id=?";
            try (PreparedStatement ps2 = conn.prepareStatement(sqlTeachers)) {
                ps2.setInt(1, id);
                try (ResultSet rs2 = ps2.executeQuery()) {
                    List<Teacher> teachers = new ArrayList<>();
                    while (rs2.next()) {
                        Teacher t = new Teacher();
                        t.setId(rs2.getInt("id"));
                        t.setPucpCode(rs2.getString("pucp_code"));
                        t.setFirstName(rs2.getString("first_name"));
                        t.setLastName(rs2.getString("last_name"));
                        teachers.add(t);
                    }
                    assessment.setTeachers(teachers);
                }
            }

            // Cargar items con preguntas
            String sqlItems = "SELECT ai.id, ai.score, ai.question_id "
                    + "FROM assessment_item ai WHERE ai.assessment_id=?";
            QuestionDAOMySQL questionDAO = new QuestionDAOMySQL();
            try (PreparedStatement ps3 = conn.prepareStatement(sqlItems)) {
                ps3.setInt(1, id);
                try (ResultSet rs3 = ps3.executeQuery()) {
                    List<AssessmentItem> items = new ArrayList<>();
                    while (rs3.next()) {
                        AssessmentItem item = new AssessmentItem();
                        item.setId(rs3.getInt("id"));
                        item.setScore(rs3.getDouble("score"));
                        item.setQuestion(questionDAO.obtenerPorIdConConexion(
                                rs3.getInt("question_id"), conn));
                        items.add(item);
                    }
                    assessment.setAssessmentItems(items);
                }
            }
        }
        return assessment;
    }

    @Override
    public List<Assessment> listar() throws Exception {
        String sql = "SELECT id, duration_in_minutes, start_date FROM assessment ORDER BY id";
        List<Assessment> lista = new ArrayList<>();
        try (Connection conn = DBFactoryProvider.getManager().getConnection();
             PreparedStatement ps = conn.prepareStatement(sql);
             ResultSet rs = ps.executeQuery()) {
            while (rs.next()) {
                lista.add(mapearResultSet(rs));
            }
        }
        return lista;
    }

    private Assessment mapearResultSet(ResultSet rs) throws Exception {
        Assessment a = new Assessment();
        a.setId(rs.getInt("id"));
        a.setDurationInMinutes(rs.getInt("duration_in_minutes"));
        a.setStartDate(rs.getTimestamp("start_date"));
        return a;
    }
}
