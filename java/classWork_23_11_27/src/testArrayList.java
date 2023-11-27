import java.util.ArrayList;

public class testArrayList {
    public static void main(String[] args) {
        ArrayList<Integer> theArray = new ArrayList<Integer>();
        for (int i = 0; i < 10; i++) {
            Integer newInteger = new Integer(i);
            theArray.add(newInteger);
        }
        for (int k = 0; k < theArray.size(); k++)
            System.out.println(theArray.get(k));
    }
}
