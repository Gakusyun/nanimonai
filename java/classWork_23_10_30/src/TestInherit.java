class BaseClass {
    private String hostName = "WPUIC";

    public String GetName() {
        return hostName;
    }

    public void OtherMethod() {
        ;
    }
}

class DerivedClass extends BaseClass {
    private String hostIP = "211.0.1.2";
    private int count = 100;

    public String GetName() {
        return hostIP;
    }

    public int GetPersonCount() {
        return count;
    }
}

public class TestInherit {
    public static void main(String[] args) {
        BaseClass b = new BaseClass();
        String s = b.GetName();
        BaseClass d = new DerivedClass();
        s = d.GetName();
        d.OtherMethod();
        System.out.println(s);
        System.out.println(b.GetName());
    }
}