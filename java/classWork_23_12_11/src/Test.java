import java.io.*;

public class Test {
    public static void main(String[] args) {
        try {
            FileInputStream fs = new FileInputStream("src.txt");
            FileOutputStream fos = new FileOutputStream("dest.txt");
            byte b;
            while ((b = (byte) fs.read()) != -1) {
                fos.write(b);
            }
            fs.close();
            fos.close();
        } catch (Exception e) {
            System.out.println(e.toString());
        }
    }
}
