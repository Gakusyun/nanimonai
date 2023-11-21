class BaseClass {
    String hostName;

    BaseClass() {
        hostName = "Army!";

    }

    BaseClass(String s) {
        hostName = s;
    }

    public String GetName() {
        return hostName;
    }
}

class DerivedClass extends BaseClass {
    DerivedClass(String s) {

    }
}

public class Test2 {
    public static void main(String[] args) {
        DerivedClass d = new DerivedClass("Tom!");
        System.out.println(d.GetName());
    }
}
