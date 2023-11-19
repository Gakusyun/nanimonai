/**
 * Face
 */
interface Face {
    public final String hostName = "WPUIP";

    String GetName();

    void GetCount();
}

abstract class InpleClass implements Face{
    String ip = "203.220.33.0";

    public String GetName() {
        return hostName;
    }
    public abstract void GetCount();
}
public class one extends InpleClass{
    public void GetCount()
    {
        System.out.println(ip);
    }
    public static void main(String[] args) {
        one o = new one();
        o.GetCount();
        String name = o.GetName();
        System.out.println(name);
    }
}