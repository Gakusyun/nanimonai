public class Test {
    public static void main(String[] args) {
        String s1 = " 200901046 ";
        Integer i = Integer.parseInt(s1.trim());
        String s2 = Integer.toString(i + 1);
        System.out.println(s2);
    }
}
