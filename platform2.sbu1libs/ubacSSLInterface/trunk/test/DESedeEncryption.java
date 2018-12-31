/*
 * javac DESedeEncryption.java
 * java DESedeEncryption
 *
 */

import java.security.spec.KeySpec;
import javax.crypto.Cipher;
import javax.crypto.SecretKey;
import javax.crypto.SecretKeyFactory;
import javax.crypto.spec.DESedeKeySpec;
import javax.crypto.spec.IvParameterSpec;
import sun.misc.BASE64Decoder;
import sun.misc.BASE64Encoder;
import java.util.Arrays;


public class DESedeEncryption {

    private static final String UNICODE_FORMAT = "UTF8";
    public static final String DESEDE_ENCRYPTION_SCHEME = "DESede";
    public static final String transformation = "DESede/CBC/PKCS5Padding";
    
    private KeySpec myKeySpec;
    private SecretKeyFactory mySecretKeyFactory;
    private Cipher cipher;
    byte[] keyAsBytes;
    private String myEncryptionKey;
    SecretKey key;
    IvParameterSpec iv;

    public static String bytesToHex(byte[] in) {
        final StringBuilder builder = new StringBuilder();
        for(byte b : in) {
            builder.append(String.format("%02x", b));
        }
        System.out.println(builder.toString());
        return builder.toString();
    }

    public DESedeEncryption() throws Exception
    {
        myEncryptionKey = "ae7f8b2c65f8987bc410d150";
        keyAsBytes = myEncryptionKey.getBytes(UNICODE_FORMAT);
        myKeySpec = new DESedeKeySpec(keyAsBytes);
        key = SecretKeyFactory.getInstance(DESEDE_ENCRYPTION_SCHEME).generateSecret(myKeySpec);
        cipher = Cipher.getInstance(transformation);
    }

    /**
     * Method To Encrypt The String
     */
    public String encrypt(String unencryptedString) {
        String encryptedString = null;
        try {

            iv = new IvParameterSpec(new byte[8]);

            cipher.init(Cipher.ENCRYPT_MODE, key, iv);
            byte[] plainText = unencryptedString.getBytes(UNICODE_FORMAT);
            byte[] encryptedText = cipher.doFinal(plainText);
            
            System.out.println("encryptedBytes in HEX: " + bytesToHex(encryptedText));

            BASE64Encoder base64encoder = new BASE64Encoder();
            encryptedString = base64encoder.encode(encryptedText);

            System.out.println("encryptedString " + encryptedString);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return encryptedString;
    }


    /**
     * Method To Decrypt An Ecrypted String
     */
    public String decrypt(String encryptedString) {
        String decryptedText=null;
        try {
            cipher.init(Cipher.DECRYPT_MODE, key, iv);
            BASE64Decoder base64decoder = new BASE64Decoder();
            byte[] encryptedText = base64decoder.decodeBuffer(encryptedString);
            byte[] plainText = cipher.doFinal(encryptedText);
            decryptedText= bytes2String(plainText);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return decryptedText;
    }

    /**
     * Returns String From An Array Of Bytes
     */
    private static String bytes2String(byte[] bytes) {
        StringBuffer stringBuffer = new StringBuffer();
        for (int i = 0; i < bytes.length; i++) {
            stringBuffer.append((char) bytes[i]);
        }
        return stringBuffer.toString();
    }

    /**
     * Testing The DESede Encryption And Decryption Technique
     */
    public static void main(String args []) throws Exception
    {
        DESedeEncryption myEncryptor= new DESedeEncryption();

        String stringToEncrypt="The quick brown fox jumps over the lazy dog.";
        String encrypted=myEncryptor.encrypt(stringToEncrypt);
        String decrypted=myEncryptor.decrypt(encrypted);

        System.out.println("String To Encrypt: "+stringToEncrypt);
        System.out.println("Encrypted Value :" + encrypted);
        System.out.println("Decrypted Value :"+decrypted);

    }

}
