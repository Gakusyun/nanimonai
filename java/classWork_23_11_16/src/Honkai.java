// 定义一个接口，包含两个方法：add(int a, int b) 和 subtract(int a, int b)。分别用于实现加法和减法运算。
// 在接口中定义一个常量字段 PI，用于表示圆周率。
// 在接口的实现类中，实现 multiply(int a, int b) 和 divide(int a, int b) 方法，用于实现乘法和除法运算。
// 在实现类中，定义一个 main 方法，用于测试实现的接口方法。

interface Impact {
    int add(int a, int b);

    int subtract(int a, int b);

    double PI = 3.1415926;

}

class Starail implements Impact {
    public int add(int a, int b) {
        return a + b;
    }

    public int subtract(int a, int b) {
        return a - b;
    }

    int multiply(int a, int b) {
        return a * b;
    }

    double divide(int a, int b) {
        return (double) a / (double) b;
    }
}

public class Honkai {
    public static void main(String[] args) {
        Starail genshin = new Starail();
        System.out.printf("5+3=%d\n", genshin.add(5, 3));
        System.out.printf("5-3=%d\n", genshin.subtract(5, 3));
        System.out.printf("5*3=%d\n", genshin.multiply(5, 3));
        System.out.printf("5/3=%f\n", genshin.divide(5, 3));
    }
}
