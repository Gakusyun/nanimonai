public class KY6_5 {
    public static void main(String[] args) {
        String s = new String("This is an demo of the String method."); // 创建一个新的字符串s
        System.out.println("Length: " + s.length()); // 打印出字符串s的长度
        System.out.println("SubString: " + s.substring(11, 15)); // 打印出字符串s的子字符串，从索引11开始到索引14
        StringBuffer sf = new StringBuffer("Hello World!"); // 创建一个新的StringBuffer对象sf
        sf.append(" Hello Java!"); // 在sf的末尾追加字符串" Hello Java!"
        sf.insert(12, " And"); // 在sf的索引12位置插入字符串" And"
        System.out.println(sf); // 打印出sf的内容
        System.out.println(sf.charAt(0)); // 打印出sf的第一个字符
        sf.setCharAt(0, 'h'); // 将sf的第一个字符设置为'h'
        System.out.println(sf.charAt(0)); // 打印出sf的第一个字符
        System.out.println(sf); // 打印出sf的内容
    }
}
