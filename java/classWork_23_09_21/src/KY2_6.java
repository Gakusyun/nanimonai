public class KY2_6 {
    public static void main(String[] args) {
        int a[] = new int[10];
        int i;
        for (i = 0; i < 10; i++)
            a[i] = (int) (Math.random() * 100);
        while (true) {
            boolean flag = false;
            for (i = 0; i < 9; i++) 
                if (a[i] > a[i + 1]) {
                    a[i] += a[i + 1];
                    a[i + 1] = a[i] - a[i + 1];
                    a[i] -= a[i + 1];
                    flag = true;
                }
                if (flag == false)
                    break;
            
        }
        for (i = 0; i < 10; i++)
            System.out.print(a[i] + " ");
    }
}
