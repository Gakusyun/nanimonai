import java.io.FileInputStream;

public class namestream {
    public static void main(String[] args) {
        try {
            FileInputStream fs = new FileInputStream("/home/Xuejun/Documents/javaClasswork_23_12_11/src.txt");
            byte[] b = new byte[255];
            fs.read(b);
            System.out.print("依次读取 byte 数组的前三个字符为：\n" + b[0]);
            System.out.print(b[1]);
            System.out.println(b[2]);
            String str = new String(b);
            System.out.println("文件内容为：\n" + str.trim());
            fs.close();
        } catch (Exception e) {

        }
    }
}
