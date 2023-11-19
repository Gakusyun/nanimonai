public class Work1 {
    public static void main(String[] args) {
        byte a = 2;
        byte b = 3;
        int y;
        y = ~a;
        System.out.println("~a=" + y);
        y = ~b;
        System.out.println("~b=" + y);
        y = a & b;
        System.out.println("a&b=" + y);
        y = a | b;
        System.out.println("a|b=" + y);
        y = a << 3;
        System.out.println("a<<3=" + y);
        y = b >> 3;
        System.out.println("b>>3=" + y);
    }
}