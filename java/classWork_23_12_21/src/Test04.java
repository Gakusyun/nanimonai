import java.util.*;

public class Test04 {
    public static void main(String[] args) {
        // 创建一个List集合
        List<String> list = new ArrayList<String>();

        // 向集合中添加数据
        list.add("abc1");
        list.add("abc2");
        list.add("abc3");
        list.add("abc4");

        // 通过调用List集合的iterator()方法获得迭代器对象
        Iterator<String> it = list.iterator();

        // 在while循环条件中使用hasNext()方法判断集合中是否存在下一个元素
        while(it.hasNext()) {
            // 如果存在，则调用next()方法将元素取出
            String s = it.next();
            System.out.println(s);
        }
        // 否则说明已到达了集合末尾，停止遍历元素
    }
}
