import java.util.Scanner;

class Box {
    private int length;
    private int width;
    private int heigth;

    public void setBox(int l, int w, int h) {
        length = l;
        width = w;
        heigth = h;
    }

    public int volume() {
        return length * width * heigth;
    }
}

public class volume {
    public static void main(String[] args) {
        Box b = new Box();
        Scanner scan = new Scanner(System.in);
        System.out.println("输入长:");
        int l = scan.nextInt();
        System.out.println("输入宽:");
        int w = scan.nextInt();
        System.out.println("输入高:");
        int h = scan.nextInt();
        scan.close();
        b.setBox(l, w, h);
        System.out.println(b.volume());
    }
}
