interface Genshin {
    int add(int x, int y);

    int jian(int x, int y);
}

public class KY6_3 implements Genshin {
    public int add(int x, int y) {
        return x + y;
    }

    public int jian(int x, int y) {
        return x - y;

    }

    public static void main(String[] args) {
        KY6_3 k = new KY6_3();
        System.out.println("3 + 5 = " + k.add(3, 5));
        System.out.println("5 - 3 = " + k.jian(5, 3));
    }
}