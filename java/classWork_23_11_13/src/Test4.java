public class Test4 {
	public static void main(String[] args) {
		String s1 = "XG200901046";
		int len = s1.length();
		Integer i = Integer.parseInt(s1.substring(2, len));
		String s2 = Integer.toString(i + 1);
		System.out.println("XG" + s2);
	}
}
