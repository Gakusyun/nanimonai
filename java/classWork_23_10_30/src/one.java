class Value1 {
    int x = 10, y = 20;
}

class Value2 extends Value1 {
    private int x;

    public int getX() {
        return this.x;
    }

    public int getOriginX() {
        return super.x;
    }
}

public class one {
    public static void main(String[] args) {
        Value2 v2 = new Value2();
        System.out.println(v2.getOriginX()); // prints 10
        System.out.println(v2.getX()); // prints 0
    }
}