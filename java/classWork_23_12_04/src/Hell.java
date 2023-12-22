import java.io.IOException;

public class Hell {
    public static void main(String[] args) throws IOException {
        byte[] cc = new byte[10];
        try {
            System.in.read(cc);
        } catch (Exception e) {
            System.out.println("error:" + e.toString());
        }
        String abc = new String(cc);
        System.out.println(abc);
        System.out.println(abc.length());
        abc = abc.trim();
        System.out.println(abc);
        System.out.println(abc.length());
    }
}
