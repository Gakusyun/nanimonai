class Point {
    int x, y;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class Circle {
    Point center;
    int radius;

    public Circle(Point center, int radius) {
        this.center = center;
        this.radius = radius;
    }

    public static double area(Circle c) {
        return Math.PI * c.radius * c.radius;
    }

    public static boolean isInside(Circle c, Point p) {
        return (p.x - c.center.x) * (p.x - c.center.x) + (p.y - c.center.y) * (p.y - c.center.y) <= c.radius * c.radius;
    }
}

public class T11 {
    public static void main(String[] args) {
        Point p = new Point(10, 10);
        Point center = new Point(0, 0);
        Circle c = new Circle(center, 10);
        System.out.println("圆的面积为" + Circle.area(c));
        System.out.println("点" + p.x + "," + p.y + "是否在圆内" + Circle.isInside(c, p));
    }
}
