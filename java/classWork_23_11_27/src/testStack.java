import java.util.*;

class Point {
    int x, y;
}

public class testStack {
    public static void main(String[] args) {
        Point p;
        Stack mystack1 = new Stack();
        for (int i = 0; i < 5; i++) {
            p = new Point();
            p.x = i;
            p.y = i * i;
            mystack1.push(p);
        }
        for (int i = 0; i < 5; i++) {
            p = (Point) mystack1.pop();
            System.out.println("x:" + p.y + " y:" + p.y);
        }
    }
}
