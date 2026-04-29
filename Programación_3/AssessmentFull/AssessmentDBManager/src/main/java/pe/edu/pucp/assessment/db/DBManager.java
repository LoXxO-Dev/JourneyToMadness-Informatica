package pe.edu.pucp.assessment.db;

import pe.edu.pucp.assessment.db.utils.Crypto;
import pe.edu.pucp.assessment.db.utils.TipoDB;

import java.sql.Connection;
import java.sql.SQLException;

public abstract class DBManager {
    protected String host;
    protected int puerto;
    protected String esquema;
    protected String usuario;
    protected String password;
    protected TipoDB tipoDB;

    protected DBManager() {}

    protected DBManager(String host, int puerto, String esquema,
                        String usuario, String password, TipoDB tipoDB) {
        try {
            this.host = host;
            this.puerto = puerto;
            this.esquema = esquema;
            this.usuario = usuario;
            this.password = Crypto.decrypt(password);
            this.tipoDB = tipoDB;
        } catch (Exception ex) {
            System.err.println("Error al configurar la conexion a la base de datos: "
                    + ex.getMessage());
            throw new RuntimeException(ex);
        }
    }

    public abstract Connection getConnection() throws SQLException, ClassNotFoundException;

    protected String cadenaConexion() {
        switch (this.tipoDB) {
            case MySQL -> {
                return String.format(
                        "jdbc:mysql://%s:%d/%s?useSSL=false&allowPublicKeyRetrieval=true",
                        host, puerto, esquema);
            }
            case MSSQL -> {
                return String.format(
                        "jdbc:sqlserver://%s:%d;databaseName=%s;encrypt=false",
                        host, puerto, esquema);
            }
            default -> throw new UnsupportedOperationException("Tipo DB no soportado: " + tipoDB);
        }
    }
}
