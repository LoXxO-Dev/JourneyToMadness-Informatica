package pe.edu.pucp.assessment.dao;

import pe.edu.pucp.assessment.model.Question;

import java.sql.Connection;
import java.util.List;

public interface QuestionDAO {
    Integer insertar(Question question, Connection connection) throws Exception;
    void actualizar(Question question, Connection connection) throws Exception;
    void eliminar(Integer id, Connection connection) throws Exception;
    Question obtenerPorId(Integer id) throws Exception;
    List<Question> listar() throws Exception;
}
