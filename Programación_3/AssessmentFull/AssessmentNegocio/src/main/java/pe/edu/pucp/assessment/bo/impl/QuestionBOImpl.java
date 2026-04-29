package pe.edu.pucp.assessment.bo.impl;

import pe.edu.pucp.assessment.bo.QuestionBO;
import pe.edu.pucp.assessment.dao.QuestionDAO;
import pe.edu.pucp.assessment.dao.mysql.QuestionDAOMySQL;
import pe.edu.pucp.assessment.db.DBFactoryProvider;
import pe.edu.pucp.assessment.model.Question;

import java.sql.Connection;
import java.util.List;

public class QuestionBOImpl implements QuestionBO {
    private final QuestionDAO questionDAO;

    public QuestionBOImpl() {
        this.questionDAO = new QuestionDAOMySQL();
    }

    @Override
    public Integer insertar(Question question) throws Exception {
        Connection connection = null;
        try {
            connection = DBFactoryProvider.getManager().getConnection();
            connection.setAutoCommit(false);

            Integer id = questionDAO.insertar(question, connection);

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
    public void actualizar(Question question) throws Exception {
        Connection connection = null;
        try {
            connection = DBFactoryProvider.getManager().getConnection();
            connection.setAutoCommit(false);

            questionDAO.actualizar(question, connection);

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

            questionDAO.eliminar(id, connection);

            connection.commit();
        } catch (Exception e) {
            if (connection != null) connection.rollback();
            throw e;
        } finally {
            if (connection != null) connection.close();
        }
    }

    @Override
    public Question obtenerPorId(Integer id) throws Exception {
        return questionDAO.obtenerPorId(id);
    }

    @Override
    public List<Question> listar() throws Exception {
        return questionDAO.listar();
    }
}
