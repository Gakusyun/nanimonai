class Point {
    int x, y, z;

    public static double distance(Point p1, Point p2) {
        return Math.pow(p1.x - p2.x, 2) + Math.pow(p1.y - p2.y, 2) + Math.pow(p1.z - p2.z, 2);
    }

    Point(int x, int y, int z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

}

public class T10 {
    public static void main(String[] args) {
        Point po = new Point(1, 2, 3);
        Point po2 = new Point(2, 3, 4);
        System.out.println(Point.distance(po, po2));
    }
}
