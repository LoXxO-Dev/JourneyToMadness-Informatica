package pe.edu.pucp.assessment.dao;

import pe.edu.pucp.assessment.model.Teacher;

import java.sql.Connection;
import java.util.List;

public interface TeacherDAO {
    Integer insertar(Teacher teacher, Connection connection) throws Exception;
    void actualizar(Teacher teacher, Connection connection) throws Exception;
    void eliminar(Integer id, Connection connection) throws Exception;
    Teacher obtenerPorId(Integer id) throws Exception;
    List<Teacher> listar() throws Exception;
}
