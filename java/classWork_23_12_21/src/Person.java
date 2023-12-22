public class Person {
    // 定义两个私有属性：姓名（name）和年龄（age）
    private String name;
    private int age;

    // 定义构造方法用来初始化数据成员
    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    // 定义显示（display()）方法将姓名和年龄打印出来
    public void display() {
        System.out.println("姓名：" + name + ", 年龄：" + age);
    }

    public static void main(String[] args) {
        // 在main方法中创建人类的实例
        Person person = new Person("张三", 25);

        // 然后将人类的姓名和年龄信息显示出来
        person.display();
    }
}
