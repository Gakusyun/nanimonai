import java.util.*;

public class Test03 {
    public static void main(String[] args) {
        // 在类中定义一个ArrayList集合
        ArrayList<Integer> list = new ArrayList<Integer>();

        // 用add()方法向集合中添加元素1，2，3，4，5
        list.add(1);
        list.add(2);
        list.add(3);
        list.add(4);
        list.add(5);

        // 用get()方法获取集合中的所有元素并输出
        for(int i = 0; i < list.size(); i++) {
            System.out.println(list.get(i));
        }
    }
}
