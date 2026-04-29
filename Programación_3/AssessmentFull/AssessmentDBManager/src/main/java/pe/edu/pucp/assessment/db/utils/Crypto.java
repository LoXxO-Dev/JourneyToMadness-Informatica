package pe.edu.pucp.assessment.db.utils;

import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;
import java.util.Base64;

public class Crypto {
    // Clave fija con proposito academico
    // En produccion debe gestionarse de forma segura
    private static final String KEY = "claveprog3202601";

    public static String encrypt(String textoPlano) throws Exception {
        SecretKeySpec keySpec = new SecretKeySpec(KEY.getBytes(), "AES");
        Cipher cipher = Cipher.getInstance("AES");
        cipher.init(Cipher.ENCRYPT_MODE, keySpec);
        byte[] encrypted = cipher.doFinal(textoPlano.getBytes());
        return Base64.getEncoder().encodeToString(encrypted);
    }

    public static String decrypt(String textoCifrado) throws Exception {
        SecretKeySpec keySpec = new SecretKeySpec(KEY.getBytes(), "AES");
        Cipher cipher = Cipher.getInstance("AES");
        cipher.init(Cipher.DECRYPT_MODE, keySpec);
        byte[] decoded = Base64.getDecoder().decode(textoCifrado);
        byte[] decrypted = cipher.doFinal(decoded);
        return new String(decrypted);
    }

    public static void main(String[] args) throws Exception {
        // Usar este main para encriptar passwords y pegar el resultado en db.properties
        String password = "labs1inf3020261";
        System.out.println("Encrypted: " + encrypt(password));
    }
}
