// 创建一个Animal类，以及两个继承自Animal类的子类Dog和Cat。Dog类和Cat类都实现了一个eat()方法，但是它们的eat()方法的实现是不同的。编写一个main()方法来测试这个程序。
// 要求：
// 创建一个Animal类，其中包含一个名为name的属性和一个名为speak()的方法。
// 创建一个Dog类，该类继承自Animal类，并实现一个eat()方法。
// 创建一个Cat类，该类继承自Animal类，并实现一个eat()方法。
// 在main()方法中创建一个Dog对象和一个Cat对象，并调用它们的eat()方法。
class Animal {
    String name;

    void speck() {
        ;
    }
}

class Dog extends Animal {
    String name = "Dog";

    void eat() {
        System.out.println(name + " eat bone");
    }
}

class Cat extends Animal {
    String name = "Cat";

    void eat() {
        System.out.println(name + " eat fish");
    }
}

public class Genshin {
    public static void main(String[] args) {
        Dog dog = new Dog();
        Cat cat = new Cat();
        dog.eat();
        cat.eat();
    }
}
