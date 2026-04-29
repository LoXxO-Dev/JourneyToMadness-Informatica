package pe.edu.pucp.assessment.bo.impl;

import pe.edu.pucp.assessment.bo.TeacherBO;
import pe.edu.pucp.assessment.dao.TeacherDAO;
import pe.edu.pucp.assessment.dao.mysql.TeacherDAOMySQL;
import pe.edu.pucp.assessment.db.DBFactoryProvider;
import pe.edu.pucp.assessment.model.Teacher;

import java.sql.Connection;
import java.util.List;

public class TeacherBOImpl implements TeacherBO {
    private final TeacherDAO teacherDAO;

    public TeacherBOImpl() {
        this.teacherDAO = new TeacherDAOMySQL();
    }

    @Override
    public Integer insertar(Teacher teacher) throws Exception {
        Connection connection = null;
        try {
            connection = DBFactoryProvider.getManager().getConnection();
            connection.setAutoCommit(false);

            Integer id = teacherDAO.insertar(teacher, connection);

            connection.commit();
            return id;
        } catch (Exception e) {
            if (connection != null) connection.rollback();
            throw e;
        } finally {
            if (connection != null) connection.close();
        }
    }

    @Override
    public void actualizar(Teacher teacher) throws Exception {
        Connection connection = null;
        try {
            connection = DBFactoryProvider.getManager().getConnection();
            connection.setAutoCommit(false);

            teacherDAO.actualizar(teacher, connection);

            connection.commit();
        } catch (Exception e) {
            if (connection != null) connection.rollback();
            throw e;
        } finally {
            if (connection != null) connection.close();
        }
    }

    @Override
    public void eliminar(Integer id) throws Exception {
        Connection connection = null;
        try {
            connection = DBFactoryProvider.getManager().getConnection();
            connection.setAutoCommit(false);

            teacherDAO.eliminar(id, connection);

            connection.commit();
        } catch (Exception e) {
            if (connection != null) connection.rollback();
            throw e;
        } finally {
            if (connection != null) connection.close();
        }
    }

    @Override
    public Teacher obtenerPorId(Integer id) throws Exception {
        return teacherDAO.obtenerPorId(id);
    }

    @Override
    public List<Teacher> listar() throws Exception {
        return teacherDAO.listar();
    }
}
