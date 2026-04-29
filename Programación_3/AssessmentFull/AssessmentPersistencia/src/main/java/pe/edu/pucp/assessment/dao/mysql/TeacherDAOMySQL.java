package pe.edu.pucp.assessment.dao.mysql;

import pe.edu.pucp.assessment.dao.TeacherDAO;
import pe.edu.pucp.assessment.db.DBFactoryProvider;
import pe.edu.pucp.assessment.model.Teacher;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

public class TeacherDAOMySQL implements TeacherDAO {

    @Override
    public Integer insertar(Teacher teacher, Connection connection) throws Exception {
        String sql = "INSERT INTO teacher (pucp_code, first_name, last_name) VALUES (?, ?, ?)";
        try (PreparedStatement ps = connection.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS)) {
            ps.setString(1, teacher.getPucpCode());
            ps.setString(2, teacher.getFirstName());
            ps.setString(3, teacher.getLastName());
            ps.executeUpdate();
            try (ResultSet rs = ps.getGeneratedKeys()) {
                if (rs.next()) {
                    Integer id = rs.getInt(1);
                    teacher.setId(id);
                    return id;
                }
            }
        }
        return null;
    }

    @Override
    public void actualizar(Teacher teacher, Connection connection) throws Exception {
        String sql = "UPDATE teacher SET pucp_code=?, first_name=?, last_name=? WHERE id=?";
        try (PreparedStatement ps = connection.prepareStatement(sql)) {
            ps.setString(1, teacher.getPucpCode());
            ps.setString(2, teacher.getFirstName());
            ps.setString(3, teacher.getLastName());
            ps.setInt(4, teacher.getId());
            ps.executeUpdate();
        }
    }

    @Override
    public void eliminar(Integer id, Connection connection) throws Exception {
        String sql = "DELETE FROM teacher WHERE id=?";
        try (PreparedStatement ps = connection.prepareStatement(sql)) {
            ps.setInt(1, id);
            ps.executeUpdate();
        }
    }

    @Override
    public Teacher obtenerPorId(Integer id) throws Exception {
        String sql = "SELECT id, pucp_code, first_name, last_name FROM teacher WHERE id=?";
        try (Connection conn = DBFactoryProvider.getManager().getConnection();
             PreparedStatement ps = conn.prepareStatement(sql)) {
            ps.setInt(1, id);
            try (ResultSet rs = ps.executeQuery()) {
                if (rs.next()) {
                    return mapearResultSet(rs);
                }
            }
        }
        return null;
    }

    @Override
    public List<Teacher> listar() throws Exception {
        String sql = "SELECT id, pucp_code, first_name, last_name FROM teacher ORDER BY last_name";
        List<Teacher> lista = new ArrayList<>();
        try (Connection conn = DBFactoryProvider.getManager().getConnection();
             PreparedStatement ps = conn.prepareStatement(sql);
             ResultSet rs = ps.executeQuery()) {
            while (rs.next()) {
                lista.add(mapearResultSet(rs));
            }
        }
        return lista;
    }

    private Teacher mapearResultSet(ResultSet rs) throws Exception {
        Teacher teacher = new Teacher();
        teacher.setId(rs.getInt("id"));
        teacher.setPucpCode(rs.getString("pucp_code"));
        teacher.setFirstName(rs.getString("first_name"));
        teacher.setLastName(rs.getString("last_name"));
        return teacher;
    }
}
