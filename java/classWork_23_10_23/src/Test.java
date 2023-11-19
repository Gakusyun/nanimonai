class BaseClass {
    String hostName;

    BaseClass() {
        hostName = "Army!";

    }

    public String GetName() {
        return hostName;
    }
}
class DerivedClass extends BaseClass {
    DerivedClass() {
        super();//错的
        super.hostName = "Bob";
        
    }
}
public class Test {
    public static void main(String[] args) {
        DerivedClass d = new DerivedClass();
        System.out.println(d.GetName());
    }
}
