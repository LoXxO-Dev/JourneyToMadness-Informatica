package pe.edu.pucp.assessment.db;

import pe.edu.pucp.assessment.db.utils.TipoDB;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class MySQLDBManager extends DBManager {
    private static MySQLDBManager instancia;

    protected MySQLDBManager() {}

    protected MySQLDBManager(String host, int puerto, String esquema,
                             String usuario, String password) {
        super(host, puerto, esquema, usuario, password, TipoDB.MySQL);
    }

    static synchronized MySQLDBManager getInstance(String host, int puerto,
                                                   String esquema,
                                                   String usuario,
                                                   String password) {
        if (instancia == null) {
            instancia = new MySQLDBManager(host, puerto, esquema, usuario, password);
        }
        return instancia;
    }

    @Override
    public Connection getConnection() throws SQLException, ClassNotFoundException {
        try {
            /*
             * Por ahora creamos una conexion cada vez que se necesita acceder
             * a la base de datos. Para uso academico es aceptable;
             * en produccion se debe usar un pool de conexiones.
             */
            Class.forName("com.mysql.cj.jdbc.Driver");
            return DriverManager.getConnection(cadenaConexion(), usuario, password);
        } catch (ClassNotFoundException | SQLException e) {
            System.err.println("Error al obtener conexion: " + e.getMessage());
            throw e;
        }
    }
}
