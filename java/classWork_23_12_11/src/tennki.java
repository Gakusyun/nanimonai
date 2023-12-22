import java.io.FileWriter;

public class tennki {
    public static void main(String[] args) {
        try{
            FileWriter fw = new FileWriter("/home/Xuejun/Documents/javaClasswork_23_12_11/src.txt");
            String s="今天天气不好";
            fw.write(s);
            fw.close();
        } catch (Exception e) {
            System.out.println(e.toString());
        }
    }
}
