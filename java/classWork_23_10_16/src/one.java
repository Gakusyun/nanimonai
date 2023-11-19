
class Location {
	int x, y;

	void show() {
		System.out.println(this.x + " " + this.y);
	}
}

class Point123 extends Location {
	boolean visible;

	Point123(int x, int y, boolean tf) {
		this.x = x;
		this.y = y;
		this.visible = tf;
	}

	void expand(int times) {

		x = x * times;
		y = y * times;
	}

	void moveTo(int x, int y) {
		this.x = x;
		this.y = y;
	}
}

public class one {
	public static void main(String[] args) {
		Point123 p = new Point123(100, 100, false);
		p.show();
		p.expand(10);
		p.show();
	}
}
