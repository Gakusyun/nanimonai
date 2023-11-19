class Value1 {
    int x, y;

    Value1(int a, int b) {
        x = a;
        y = b;
        System.out.println("Value1");
    }

    int GetX() {
        return x;
    }
}

class Value2 extends Value1 {
    Value2(int a, int b) {
        super(a, b);
        System.out.println("Value2");
    }
}

public class Var2 {
    public static void main(String[] args) {
        int t;
        Value2 v2 = new Value2(10, 20);
        t = v2.GetX() + v2.GetX();
        System.out.println("add = " + t);
    }
}
