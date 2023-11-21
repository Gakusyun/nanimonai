public class Work_1 {
    public static void main(String[] args) {
        int a[] = new int[10];
        int i, max, min;
        for (i = 0; i < 10; i++)
            a[i] = (int) (Math.random() * 100);
        max = 0;
        min = 100;
        for (i = 0; i < 10; i++) {
            if (a[i] > max)
                max = a[i];
            if (a[i] < min)
                min = a[i];
        }
        System.out.println("Max = " + max);
        System.out.println("Min = " + min);

    }
}
