// 3.编写一个Java应用程序，该程序包括3个类：Animal、Monkey类和测试类。
// （1）Animal有name(名字)、age(年龄)两个属性。有个带参构造方法，并且有个speak()抽象方法； 
// （2）Monkey是Animal的子类，显示调用父类的带参构造方法，在Monkey类中重写父类的方法speak(),在speak方法中输出“别说话！”的信息。在Monkey类中新增方法void think()，在think方法中输出“认真思考！”。
// （3）测试类中测试程序，分别调用speak()方法和think()方法。
abstract class Animal {
    String name;
    int age;

    public abstract void speak();

    public Animal(int age, String name) {
        this.age = age;
        this.name = name;
    }
}

class Monkey extends Animal {

    public Monkey(int age, String name) {
        super(age, name);
    }

    public void speak() {
        System.out.println("别说话！");
    }

    void think() {
        System.out.println("认真思考！");
    }
}

public class zooo {
    public static void main(String[] args) {
        Monkey monkey = new Monkey(5, "George");
        monkey.speak();  // 调用speak方法
        monkey.think(); 
    }
}
