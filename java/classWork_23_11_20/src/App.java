import java.util.Vector;

public class App {

    public static void main(String[] args) {
        Vector theVector = new Vector();
        for (int i = 0; i < 10; i++) {
            Integer newInteger = new Integer(i);
            theVector.addElement(newInteger);

        }
        for (int k = 0; k < theVector.size(); k++)
            System.out.println(theVector.elementAt(k));
    }
}