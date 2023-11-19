class Father {
    void speak() {
        System.out.println("I am Father");
    }
}

class son extends Father {
    void speak() {
        System.out.println("I am Son");
    }
}

public class two {
    public static void main(String[] args) {
        Father f = new Father();
        f.speak();
        son s = new son();
        s.speak();
    }
}
