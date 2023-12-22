import java.io.FileReader;

public class namechar {
    public static void main(String[] args) {
        try {
            FileReader fs = new FileReader("/home/Xuejun/Documents/javaClasswork_23_12_11/src.txt");
            char[] b = new char[255];
            fs.read(b);
            System.out.print("依次读取字符数组的前三个字符为：\n" + b[0]);
            System.out.print(b[1]);
            System.out.println(b[2]);
            String str = new String(b);
            System.out.println("文件内容为：\n"+str.trim());
            fs.close();
        } catch (Exception e) {
        }
    }
}
