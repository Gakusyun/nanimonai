import java.util.Scanner;

class Fraction {
    private int f1, f2;

    public Fraction(int f1, int f2) {
        this.f1 = f1;
        if (f2 == 0) {
            System.out.println("分母不能为0");
            return;
        }
        this.f2 = f2;
    }

    public Fraction plus(Fraction fr1) {
        return new Fraction(f1 * fr1.f2 + f2 * fr1.f1, f2 * fr1.f2);
    }

    public Fraction minus(Fraction fr1) {
        return new Fraction(f1 * fr1.f2 - f2 * fr1.f1, f2 * fr1.f2);
    }

    public Fraction multiply(Fraction fr1) {
        return new Fraction(f1 * fr1.f1, f2 * fr1.f2);
    }

    public Fraction division(Fraction fr1) {
        if (fr1.f1 == 0) {
            System.out.println("除数不能为0");
            return new Fraction(f1, f2);
        }
        return new Fraction(f1 * fr1.f2, f2 * fr1.f1);
    }

    public void prFrFlo(Fraction fr) {
        System.out.println((float) fr.f1 / (float) fr.f2);
    }

    public void prFrInt(Fraction fr) {
        System.out.println(fr.f1 + "/" + fr.f2);
    }

    public Fraction Reduction(Fraction fr) {
        for (int i = 2; i <= (fr.f1 > fr.f2 ? fr.f1 : fr.f2); i++) {
            if (fr.f1 % i == 0 && fr.f2 % i == 0) {
                fr.f1 /= 2;
                fr.f2 /= 2;
                i = 1;
            }
        }
        return fr;
    }
}

public class Shiyan_1 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("输入分子（整形）： ");
        int f1 = scan.nextInt();
        System.out.println("输入分母（整形）： ");
        int f2 = scan.nextInt();
        Fraction fr = new Fraction(f1, f2);
        System.out.println("1.加");
        System.out.println("2.减");
        System.out.println("3.乘");
        System.out.println("4.除");
        System.out.println("5.打印（a/b）");
        System.out.println("6.打印（浮点型）");
        System.out.println("7.约分至最简");
        System.out.println("0.退出");
        System.out.println("输入要进行的操作（0~6)：");
        while (true) {
            int choise = scan.nextInt();
            switch (choise) {
                case 0:
                    scan.close();
                    return;
                case 1:
                    System.out.println("输入分子（整形）： ");
                    f1 = scan.nextInt();
                    System.out.println("输入分母（整形）： ");
                    f2 = scan.nextInt();
                    fr = fr.plus(new Fraction(f1, f2));
                    break;
                case 2:
                    System.out.println("输入分子（整形）： ");
                    f1 = scan.nextInt();
                    System.out.println("输入分母（整形）： ");
                    f2 = scan.nextInt();
                    fr = fr.minus(new Fraction(f1, f2));
                    break;
                case 3:
                    System.out.println("输入分子（整形）： ");
                    f1 = scan.nextInt();
                    System.out.println("输入分母（整形）： ");
                    f2 = scan.nextInt();
                    fr = fr.multiply(new Fraction(f1, f2));
                    break;
                case 4:
                    System.out.println("输入分子（整形）： ");
                    f1 = scan.nextInt();
                    System.out.println("输入分母（整形）： ");
                    f2 = scan.nextInt();
                    fr = fr.division(new Fraction(f1, f2));
                    break;
                case 5:
                    fr.prFrInt(fr);
                    break;
                case 6:
                    fr.prFrFlo(fr);
                    break;
                case 7:
                    fr.Reduction(fr);
                    break;
                default:
                    System.out.println("输入错误，请重新输入！");
                    break;
            }

        }
    }
}