import java.util.Scanner;

public class KY2_5_3 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("请输入年份");
        int year = scan.nextInt();
        scan.close();
        if (year % 4 != 0)
            System.out.println(year + " 不是闰年");
        else if (year % 100 != 0)
            System.out.println(year + " 是闰年");
        else if (year % 400 == 0)
            System.out.println(year + " 是闰年");
        else
            System.out.println(year + " 不是闰年");
    }
}