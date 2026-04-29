package pe.edu.pucp.assessment.bo;

import pe.edu.pucp.assessment.model.Teacher;

import java.util.List;

public interface TeacherBO {
    Integer insertar(Teacher teacher) throws Exception;
    void actualizar(Teacher teacher) throws Exception;
    void eliminar(Integer id) throws Exception;
    Teacher obtenerPorId(Integer id) throws Exception;
    List<Teacher> listar() throws Exception;
}
