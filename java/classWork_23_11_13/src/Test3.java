public class Test3 {
	public static void main(String[] args) {
		String s1 = "XG200901046";
		int index = s1.indexOf("XG");
		Integer i = Integer.parseInt(s1.substring(index + 2, 11));
		String s2 = Integer.toString(i + 1);
		System.out.println("XG" + s2);
	}
}
