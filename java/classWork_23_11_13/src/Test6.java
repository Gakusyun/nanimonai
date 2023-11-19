import java.util.*;

public class Test6 {
    public static void main(String[] args) {
        Calendar c = Calendar.getInstance();
        System.out.println("今年是：" + c.get(Calendar.YEAR) + "年");
        System.out.println("本月月份是：" + (c.get(Calendar.MONTH) + 1) + "月");
        System.out.println("今天为本月第：" + c.get(Calendar.DAY_OF_MONTH) + "天");
        c.set(Calendar.DAY_OF_MONTH, 11);
        System.out.println("今天为本月第：" + c.get(Calendar.DAY_OF_MONTH) + "天");
    }
}
