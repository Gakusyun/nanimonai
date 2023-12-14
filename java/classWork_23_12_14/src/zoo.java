// 2.按以下要求编写Java程序：
// (1) 编写Animal接口，接口中声明run() 方法；
// (2) 定义Bird类和Fish类实现Animal接口；
// (3) 编写Bird类和Fish类的测试程序，并调用其中的run()方法。

interface Animal {
    public void run();
}

class Bird implements Animal {
    @Override
    public void run() {
        System.out.println("Fly to the sky!");
    }
}
class Fish implements Animal {
    @Override
    public void run() {
        System.out.println("Swimming in the river");
        
    }
}
public class zoo {
    public static void main(String[] args) {
        Bird bi = new Bird();
        Fish fi = new Fish();
        bi.run();
        fi.run();
    }
}
