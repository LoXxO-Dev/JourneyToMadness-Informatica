package pe.edu.pucp.assessment.db;

import pe.edu.pucp.assessment.db.utils.TipoDB;

import java.util.ResourceBundle;

public class DBFactoryProvider {
    private static DBManager instancia;

    public static synchronized DBManager getManager() {
        if (instancia == null) {
            ResourceBundle properties = ResourceBundle.getBundle("db");

            String host     = properties.getString("db.host");
            int puerto      = Integer.parseInt(properties.getString("db.puerto"));
            String esquema  = properties.getString("db.esquema");
            String usuario  = properties.getString("db.usuario");
            String password = properties.getString("db.password");
            TipoDB tipo     = TipoDB.valueOf(properties.getString("db.tipo"));

            DBManagerFactory factory;
            switch (tipo) {
                case MySQL -> factory = new MySQLDBManagerFactory();
                default    -> throw new IllegalArgumentException("Tipo DB no soportado: " + tipo);
            }

            instancia = factory.crearDBManager(host, puerto, esquema, usuario, password);
        }
        return instancia;
    }
}
