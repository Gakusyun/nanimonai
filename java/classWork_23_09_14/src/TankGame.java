public class TankGame {
    public static void main(String[] args) {
        final int WINDOW_WIDTH = 800;
        final int WINDOW_HEIGHT = 600;
        final float PI = 3.1415926F;
        int x = 0;
        int y = 0;
        int w = 50;
        int h = 50;
        int speed = 10;
        boolean isLive = true;
        float direction = PI / 4;
        int bulletSpeed = speed * 2;
        System.out.println("坦克位置x=" + x + "y=" + y);
        System.out.println("坦克向右横向运动一帧");
        x = x + speed;
        System.out.println("坦克位置x1=" + x + "y1=" + y);
        System.out.println("坦克向下纵向运动一帧");
        y = y + speed;
        System.out.println("坦克位置x2=" + x + "y2=" + y);
        System.out.println("坦克斜向45°运动一帧");
        x += speed * Math.cos(direction);
        y += speed * Math.cos(direction);
        System.out.println("坦克位置x3=" + x + "y3=" + y);

    }
}
