public class Test5 {
	public static void main(String[] args) {
		StringBuffer s1 = new StringBuffer(2);
		System.out.println("OrginCapacity=" + s1.capacity());
		System.out.println(s1.length());
		String str = "Study";
		s1.append(str);
		System.out.println("Newcapacity=" + s1.capacity());
		System.out.println(s1.length());
	}
}
