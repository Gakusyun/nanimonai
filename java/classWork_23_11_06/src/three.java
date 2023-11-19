interface interCalArea {
    Double PI = 3.14159;

    double cal(double r);

}
/**
 * Scalable
 */
interface Scalable {
    double Ratio = 0.5;

    double SetScale(double b);
    
}
public class three implements interCalArea,Scalable{
    public double cal(double r) {
        return r * r * PI;
    }

    public double SetScale(double b) {
        return Ratio * b;
    }
    public static void main(String[] args) {
        three testInter = new three();
        double area = testInter.cal(10.0);
        double d = testInter.SetScale(area);
        System.out.println(d);
    }
}
