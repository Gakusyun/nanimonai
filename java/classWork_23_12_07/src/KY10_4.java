import java.io.*;

public class KY10_4 {
    public static void main(String arg[]) {
        try {
            FileOutputStream fout = new FileOutputStream("KY5_6.txt", true);
            DataOutputStream dout = new DataOutputStream(fout);
            dout.writeInt(1);
            dout.writeChars("罗马" + "\n");
            dout.writeInt(2);
            dout.writeChars("北京" + "\n");
            dout.close();
        } catch (IOException ioe) {
        }
        try {
            FileInputStream fin = new FileInputStream("KY5_6.txt");
            DataInputStream din = new DataInputStream(fin);
            int i = din.readInt();
            while (i != -1)
            {
                System.out.print(i + " ");
                char ch;
                while ((ch = din.readChar()) != '\n')
                    System.out.print(ch);
                System.out.println();
                i = din.readInt();
            }
            din.close();
        } catch (IOException ioe) {
        }
    }
}