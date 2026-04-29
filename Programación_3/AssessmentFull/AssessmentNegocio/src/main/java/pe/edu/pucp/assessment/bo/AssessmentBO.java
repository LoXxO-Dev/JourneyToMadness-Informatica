package pe.edu.pucp.assessment.bo;

import pe.edu.pucp.assessment.model.Assessment;

import java.util.List;

public interface AssessmentBO {
    Integer insertar(Assessment assessment) throws Exception;
    void actualizar(Assessment assessment) throws Exception;
    void eliminar(Integer id) throws Exception;
    Assessment obtenerPorId(Integer id) throws Exception;
    List<Assessment> listar() throws Exception;
}
