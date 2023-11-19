public class KY2_4 {
    public static void main(String[] args) {
        int sum = 0;
        for (int i = 1; i <= 100; i++) {
            for (int j = 2; j <= i; j++) {
                if (i % j == 0)
                    if (j == i)
                        // System.out.println(i);
                        sum += i;
                    else
                        break;

            }
        }
        System.out.println("1到100之间的素数之和为" + sum);
    }
}
