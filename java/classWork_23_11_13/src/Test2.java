public class Test2 {
	public static void main(String[] args) {
		String s1 = "XG200901046";
		Integer i = Integer.parseInt(s1.substring(2, 11));
		String s2 = Integer.toString(i + 1);
		System.out.println("XG" + s2);
	}
}
