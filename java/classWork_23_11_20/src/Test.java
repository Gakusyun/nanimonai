import java.util.Vector;

class point {
    int x, y;

    public point(int i, int j) {
        x = i;
        y = j;
    }
}

public class Test {

    public static void main(String[] args) {
        Vector theVector = new Vector();
        for (int i = 0; i < 10; i++) {
            point val = new point(i, i * i);
            theVector.addElement(val);
        }
        for (int k = 0; k < theVector.size(); k++)
            System.out.println(((point)theVector.elementAt(k)).y);
    }
}