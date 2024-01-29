import javax.swing.*;
import java.awt.*;

public class Main {
    public static void main(String[] args) {
        // 创建主窗口
        JFrame mainFrame = new JFrame("主窗口");
        mainFrame.setSize(400, 200);
        mainFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // 创建一个可自动换行的 JLabel （使用 HTML 标签 <html> 和 <br>）
        String labelText = "这是一段很长的文本，它会在这里自动换行。<br>这是第二ddddddddddddddddddddddddddddssssssssssssssssssssddddddddddddddddd行...";
        JLabel label = new JLabel("<html>" + labelText.replaceAll("\n", "<br>") + "</html>");

        // 设置 JLabel 的宽度以适应父容器，这样当父容器尺寸改变时，文本将自动调整换行
        label.setHorizontalAlignment(JLabel.LEFT);
        label.setVerticalAlignment(JLabel.TOP);
        label.setPreferredSize(new Dimension(Integer.MAX_VALUE, 100)); // 设置一个初始高度

        // 将 JLabel 添加到主窗口中心
        mainFrame.add(label, BorderLayout.CENTER);

        // 设置主窗口可见
        mainFrame.setVisible(true);
    }
}