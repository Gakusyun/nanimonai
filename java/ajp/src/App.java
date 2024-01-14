import java.awt.*;

public class App {
    public static void main(String args[]) {
        Frame f = new Frame("我的第一个JAVA图形界面窗口");
        f.setBackground(Color.white);
        f.setVisible(true);
        f.setSize(400, 400);
        f.setLocation(200, 200);
        f.setResizable(true);
        
    }
}