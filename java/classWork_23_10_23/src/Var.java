class Value1 {
    int x, y;

    public int Getx() {
        return x;
    }

    public int Gety() {
        return y;
    }
}

class Value2 extends Value1 {
    int x;

    void show() {
        super.x = 10;
        this.x = 100;
        System.out.println(super.Getx() + " " + this.Gety() + " " + Getx());
    }

    public int Getx() {
        return x;
    }
}

public class Var {
    public static void main(String[] args) {
        Value2 v2 = new Value2();
        v2.show();
    }
}
