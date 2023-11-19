public class Work2 {
    public static void main(String[] args) {
        byte b = 3;
        int k = b;
        System.out.println(k);
        // byte x = k;
        byte x = (byte) k;
        System.out.println(x);
    }
}