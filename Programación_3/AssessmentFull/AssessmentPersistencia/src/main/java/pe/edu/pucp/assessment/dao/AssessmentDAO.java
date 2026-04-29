package pe.edu.pucp.assessment.dao;

import pe.edu.pucp.assessment.model.Assessment;

import java.sql.Connection;
import java.util.List;

public interface AssessmentDAO {
    Integer insertar(Assessment assessment, Connection connection) throws Exception;
    void actualizar(Assessment assessment, Connection connection) throws Exception;
    void eliminar(Integer id, Connection connection) throws Exception;
    Assessment obtenerPorId(Integer id) throws Exception;
    List<Assessment> listar() throws Exception;
}
