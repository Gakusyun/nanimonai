import java.util.Vector;

class point {
    int x, y;

    public point(int i, int j) {
        x = i;
        y = j;
    }
}

public class Test2 {

    public static void main(String[] args) {
        Vector<point> theVector = new Vector<point>();
        for (int i = 0; i < 10; i++) {
            point val = new point(i, i * i);
            theVector.addElement(val);
        }
        for (int k = 0; k < theVector.size(); k++)
            System.out.println(theVector.elementAt(k).y);
    }
}