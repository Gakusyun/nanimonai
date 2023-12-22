import java.util.Scanner;

public class xxx {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("int:");
        int i = scan.nextInt();
        System.out.print("string:");
        String s = scan.next();
        System.out.print("double:");
        Double d = scan.nextDouble();
        System.out.println(i);
        System.out.println(s);
        System.out.println(d);
        scan.close();
    }
}
