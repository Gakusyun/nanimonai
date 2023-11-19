abstract class A {
    abstract void callme();

    void metoo() {
        System.out.println("metoo in A");
    }
}

class B extends A {
    void callme() {
        System.out.println("Callme in B");
    }
}

public class FIrstVariable {
    public static void main(String[] args) {
        A a = new B();
        a.callme();
        a.metoo();
    }
}
