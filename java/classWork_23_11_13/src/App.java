public class App {
    public static void main(String[] args) throws Exception {
        Integer c = new Integer("123");
        String s = new String("456");
        System.out.println(c.toString());
        System.out.println(c.parseInt(s));
        System.out.println(c.valueOf(s).intValue());
    }
}
