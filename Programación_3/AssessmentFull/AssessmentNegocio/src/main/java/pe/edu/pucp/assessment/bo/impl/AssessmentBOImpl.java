package pe.edu.pucp.assessment.bo.impl;

import pe.edu.pucp.assessment.bo.AssessmentBO;
import pe.edu.pucp.assessment.dao.AssessmentDAO;
import pe.edu.pucp.assessment.dao.mysql.AssessmentDAOMySQL;
import pe.edu.pucp.assessment.db.DBFactoryProvider;
import pe.edu.pucp.assessment.model.Assessment;

import java.sql.Connection;
import java.util.List;

public class AssessmentBOImpl implements AssessmentBO {
    private final AssessmentDAO assessmentDAO;

    public AssessmentBOImpl() {
        this.assessmentDAO = new AssessmentDAOMySQL();
    }

    @Override
    public Integer insertar(Assessment assessment) throws Exception {
        Connection connection = null;
        try {
            connection = DBFactoryProvider.getManager().getConnection();
            connection.setAutoCommit(false);

            // Transaccion unica: inserta assessment + teachers + items atomicamente
            Integer id = assessmentDAO.insertar(assessment, connection);

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
    public void actualizar(Assessment assessment) throws Exception {
        Connection connection = null;
        try {
            connection = DBFactoryProvider.getManager().getConnection();
            connection.setAutoCommit(false);

            assessmentDAO.actualizar(assessment, connection);

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

            assessmentDAO.eliminar(id, connection);

            connection.commit();
        } catch (Exception e) {
            if (connection != null) connection.rollback();
            throw e;
        } finally {
            if (connection != null) connection.close();
        }
    }

    @Override
    public Assessment obtenerPorId(Integer id) throws Exception {
        return assessmentDAO.obtenerPorId(id);
    }

    @Override
    public List<Assessment> listar() throws Exception {
        return assessmentDAO.listar();
    }
}
