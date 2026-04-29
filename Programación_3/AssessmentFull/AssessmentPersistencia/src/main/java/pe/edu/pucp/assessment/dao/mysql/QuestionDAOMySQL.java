package pe.edu.pucp.assessment.dao.mysql;

import pe.edu.pucp.assessment.dao.QuestionDAO;
import pe.edu.pucp.assessment.db.DBFactoryProvider;
import pe.edu.pucp.assessment.model.Question;
import pe.edu.pucp.assessment.model.TipoQuestion;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

public class QuestionDAOMySQL implements QuestionDAO {

    @Override
    public Integer insertar(Question question, Connection connection) throws Exception {
        // 1. Insertar la pregunta
        String sqlQuestion = "INSERT INTO question (prompt, tipo) VALUES (?, ?)";
        try (PreparedStatement ps = connection.prepareStatement(sqlQuestion, Statement.RETURN_GENERATED_KEYS)) {
            ps.setString(1, question.getPrompt());
            ps.setString(2, question.getTipo().name());
            ps.executeUpdate();
            try (ResultSet rs = ps.getGeneratedKeys()) {
                if (rs.next()) {
                    question.setId(rs.getInt(1));
                }
            }
        }

        // 2. Insertar opciones disponibles
        String sqlOption = "INSERT INTO question_option (question_id, numero_opcion, descripcion) VALUES (?, ?, ?)";
        try (PreparedStatement ps = connection.prepareStatement(sqlOption)) {
            List<String> options = question.getAvailableOptions();
            for (int i = 0; i < options.size(); i++) {
                ps.setInt(1, question.getId());
                ps.setInt(2, i + 1);
                ps.setString(3, options.get(i));
                ps.addBatch();
            }
            ps.executeBatch();
        }

        // 3. Insertar respuesta(s) correcta(s)
        String sqlAnswer = "INSERT INTO question_answer (question_id, numero_opcion) VALUES (?, ?)";
        try (PreparedStatement ps = connection.prepareStatement(sqlAnswer)) {
            if (question.getTipo() == TipoQuestion.SINGLE_CHOICE) {
                ps.setInt(1, question.getId());
                ps.setInt(2, question.getCorrectOption());
                ps.executeUpdate();
            } else {
                for (Integer correctOpt : question.getCorrectOptions()) {
                    ps.setInt(1, question.getId());
                    ps.setInt(2, correctOpt);
                    ps.addBatch();
                }
                ps.executeBatch();
            }
        }

        return question.getId();
    }

    @Override
    public void actualizar(Question question, Connection connection) throws Exception {
        String sql = "UPDATE question SET prompt=?, tipo=? WHERE id=?";
        try (PreparedStatement ps = connection.prepareStatement(sql)) {
            ps.setString(1, question.getPrompt());
            ps.setString(2, question.getTipo().name());
            ps.setInt(3, question.getId());
            ps.executeUpdate();
        }
        // Actualizar opciones: eliminar y reinsertar
        try (PreparedStatement ps = connection.prepareStatement(
                "DELETE FROM question_option WHERE question_id=?")) {
            ps.setInt(1, question.getId());
            ps.executeUpdate();
        }
        try (PreparedStatement ps = connection.prepareStatement(
                "DELETE FROM question_answer WHERE question_id=?")) {
            ps.setInt(1, question.getId());
            ps.executeUpdate();
        }
        // Reinsertar opciones y respuestas usando logica del insertar
        insertar(question, connection);
    }

    @Override
    public void eliminar(Integer id, Connection connection) throws Exception {
        // Las tablas hijas se eliminan por CASCADE o manualmente
        try (PreparedStatement ps = connection.prepareStatement(
                "DELETE FROM question_answer WHERE question_id=?")) {
            ps.setInt(1, id);
            ps.executeUpdate();
        }
        try (PreparedStatement ps = connection.prepareStatement(
                "DELETE FROM question_option WHERE question_id=?")) {
            ps.setInt(1, id);
            ps.executeUpdate();
        }
        try (PreparedStatement ps = connection.prepareStatement(
                "DELETE FROM question WHERE id=?")) {
            ps.setInt(1, id);
            ps.executeUpdate();
        }
    }

    @Override
    public Question obtenerPorId(Integer id) throws Exception {
        try (Connection conn = DBFactoryProvider.getManager().getConnection()) {
            return obtenerPorIdConConexion(id, conn);
        }
    }

    public Question obtenerPorIdConConexion(Integer id, Connection conn) throws Exception {
        String sql = "SELECT id, prompt, tipo FROM question WHERE id=?";
        Question question = null;
        try (PreparedStatement ps = conn.prepareStatement(sql)) {
            ps.setInt(1, id);
            try (ResultSet rs = ps.executeQuery()) {
                if (rs.next()) {
                    question = new Question();
                    question.setId(rs.getInt("id"));
                    question.setPrompt(rs.getString("prompt"));
                    question.setTipo(TipoQuestion.valueOf(rs.getString("tipo")));
                }
            }
        }
        if (question == null) return null;

        // Cargar opciones disponibles
        String sqlOpts = "SELECT numero_opcion, descripcion FROM question_option WHERE question_id=? ORDER BY numero_opcion";
        try (PreparedStatement ps = conn.prepareStatement(sqlOpts)) {
            ps.setInt(1, id);
            try (ResultSet rs = ps.executeQuery()) {
                List<String> options = new ArrayList<>();
                while (rs.next()) {
                    options.add(rs.getString("descripcion"));
                }
                question.setAvailableOptions(options);
            }
        }

        // Cargar respuestas correctas
        String sqlAns = "SELECT numero_opcion FROM question_answer WHERE question_id=? ORDER BY numero_opcion";
        try (PreparedStatement ps = conn.prepareStatement(sqlAns)) {
            ps.setInt(1, id);
            try (ResultSet rs = ps.executeQuery()) {
                List<Integer> answers = new ArrayList<>();
                while (rs.next()) {
                    answers.add(rs.getInt("numero_opcion"));
                }
                if (question.getTipo() == TipoQuestion.SINGLE_CHOICE && !answers.isEmpty()) {
                    question.setCorrectOption(answers.get(0));
                } else {
                    question.setCorrectOptions(answers);
                }
            }
        }
        return question;
    }

    @Override
    public List<Question> listar() throws Exception {
        String sql = "SELECT id FROM question ORDER BY id";
        List<Question> lista = new ArrayList<>();
        try (Connection conn = DBFactoryProvider.getManager().getConnection();
             PreparedStatement ps = conn.prepareStatement(sql);
             ResultSet rs = ps.executeQuery()) {
            while (rs.next()) {
                lista.add(obtenerPorIdConConexion(rs.getInt("id"), conn));
            }
        }
        return lista;
    }
}
