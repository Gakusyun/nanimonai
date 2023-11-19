class Value1 {
    public int x = 10, y = 20;
}

class Value2 extends Value1 {
    private int x;
}

public class Simple {
    public static void main(String[] args) {
        Value2 v2 = new Value2();
        // System.out.println(v2.x);x是 private 这里无法使用
    }
}
