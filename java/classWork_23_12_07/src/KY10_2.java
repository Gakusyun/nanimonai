import java.io.*;

public class KY10_2 {
    public static void main(String[] args) throws IOException {
        FileReader in = new FileReader("KY10_2.HTML");
        BufferedReader bin = new BufferedReader(in);
        FileWriter out = new FileWriter("KY10_2.txt", true);
        String str;
        while ((str = bin.readLine()) != null) {
            System.out.println(str);
            out.write(str + "\n");
        }
        in.close();
        out.close();
    }
}