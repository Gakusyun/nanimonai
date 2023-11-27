import java.util.ArrayList;

public class testArrayList2 {
    public static void main(String[] args) {
        ArrayList<ArrayList<Integer>> vArr = new ArrayList<ArrayList<Integer>>();
        ArrayList<Integer> strV3 = new ArrayList<Integer>();
        strV3.add(1);
        strV3.add(2);
        strV3.add(3);
        strV3.add(4);
        strV3.add(5);
        ArrayList<Integer> strV4 = new ArrayList<Integer>();
        strV4.add(6);
        strV4.add(7);
        strV4.add(8);
        strV4.add(9);
        vArr.add(strV3);
        vArr.add(strV4);
        for (ArrayList<Integer> arr : vArr)
            for (Integer s : arr)
                System.out.println(s);
    }
}
