package pe.edu.pucp.assessment.bo;

import pe.edu.pucp.assessment.model.Question;

import java.util.List;

public interface QuestionBO {
    Integer insertar(Question question) throws Exception;
    void actualizar(Question question) throws Exception;
    void eliminar(Integer id) throws Exception;
    Question obtenerPorId(Integer id) throws Exception;
    List<Question> listar() throws Exception;
}
