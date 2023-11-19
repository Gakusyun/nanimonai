class BaseClass {
    private String hostName;

    BaseClass() {
        hostName = "Army";
    }

    public String getHostName() {
        return hostName;
    }
}

class DerivedClass extends BaseClass {
}

public class TestInherit {
    public static void main(String[] args) {
        DerivedClass d = new DerivedClass();
        System.out.println(d.getHostName());
    }
}
