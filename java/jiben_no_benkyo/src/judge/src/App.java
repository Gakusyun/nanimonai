import java.util.Scanner;

public class App {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("输入一个字母");
        char le = scan.next().charAt(0);
        if (le >= 'a' && le <= 'z') {
            System.out.println("是小写字母");
        } else if (le >= 'A' && le <= 'Z') {
            System.out.println("是大写字母");
        } else
            System.out.println("是其他字符");
        scan.close();
    }
}
