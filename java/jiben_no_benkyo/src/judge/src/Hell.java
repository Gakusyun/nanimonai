class Point {
    int x;
    int y;
    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
    void setX(int x) {
        this.x = x;
    }
    int getX() {
        return this.x;
    }
}
public class Hell {
    public static void main(String[] args) {
        Point p1 = new Point(10, 20);
        Point p2 = new Point(100, 200);
        Point p3 = p2;
        p2 = p1;
        p2.setX(101);
        p2 = p3;
        System.out.println(p1.getX());
        System.out.println(p2.getX());
        System.out.println(p3.getX());
    }
}
