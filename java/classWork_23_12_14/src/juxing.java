// 4. 编写一个矩形类Rectangle;将长length与宽width作为矩形类的属性，编写setLength()和setWidth()方法分别实现长和宽的设置，并定义一个成员方法getArea()求此矩形的面积。
// 标准的Java类
// (1)、属性用private,方法public
// (2)、两个构造方法，一个是无参数，一个是带全部参数的，无参数构造方法里面可以用this()调用有参数构造方法。
// (3)对所有的属性要有set和get方法来设置值
class Rectangle {
    private double length;
    private double width;

    // 无参数构造方法
    public Rectangle() {
        this(0, 0);
    }

    // 带全部参数的构造方法
    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    // 设置长度的方法
    public void setLength(double length) {
        this.length = length;
    }

    // 获取长度的方法
    public double getLength() {
        return this.length;
    }

    // 设置宽度的方法
    public void setWidth(double width) {
        this.width = width;
    }

    // 获取宽度的方法
    public double getWidth() {
        return this.width;
    }

    // 计算面积的方法
    public double getArea() {
        return this.length * this.width;
    }
}

public class juxing {
    public static void main(String[] args) {
        // 创建一个矩形对象
        Rectangle rectangle = new Rectangle(5, 10);

        // 输出矩形的长和宽
        System.out.println("Length: " + rectangle.getLength());
        System.out.println("Width: " + rectangle.getWidth());

        // 计算并输出矩形的面积
        double area = rectangle.getArea();
        System.out.println("Area: " + area);
    }
}
