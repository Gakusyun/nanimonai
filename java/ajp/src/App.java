import javax.swing.*;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;

import java.awt.*;

public class App {
    static String Text = "我能吞下玻璃而不伤身体。";
    static JLabel label = new JLabel("<html>" + Text.replaceAll("\n", "<br>") + "</html>");
    static JFrame mainFrame;
    static JSpinner fontSizeSpinner = new JSpinner(new SpinnerNumberModel(16, 8, 72, 1));
    static JComboBox<String> fontComboBox = createFontComboBox();
    static JTextField textfield = new JTextField(Text);

    public static void main(String[] args) {
        fontComboBox.setSelectedItem("微软雅黑");
        // 创建主窗口
        mainFrame = new JFrame("主窗口");
        mainFrame.setSize(400, 300);
        mainFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // 创建标签并设置默认字体
        label.setFont(new Font((String) fontComboBox.getSelectedItem(), Font.PLAIN, (int) fontSizeSpinner.getValue()));

        fontComboBox.addActionListener(e -> changeLabelFont((String) fontComboBox.getSelectedItem()));

        // 创建字体大小选择器（Spinner）

        fontSizeSpinner.addChangeListener(e -> {
            label.setFont(
                    new Font((String) fontComboBox.getSelectedItem(), Font.PLAIN, (int) fontSizeSpinner.getValue()));
        });
        // 创建文本框并添加监听器
        textfield.getDocument().addDocumentListener(new DocumentListener() {
            @Override
            public void insertUpdate(DocumentEvent e) {
                updateLabelText();
            }

            @Override
            public void removeUpdate(DocumentEvent e) {
                updateLabelText();
            }

            @Override
            public void changedUpdate(DocumentEvent e) {
                updateLabelText();
            }

            private void updateLabelText() {
                String newText = textfield.getText();
                label.setText("<html>"+newText+"</html>");
            }
        });
        // 将标签、字体下拉框和字体大小选择器添加到主窗口
        JPanel panel = new JPanel(new BorderLayout());
        panel.add(fontComboBox, BorderLayout.CENTER);
        panel.add(fontSizeSpinner, BorderLayout.EAST);

        mainFrame.add(textfield, BorderLayout.SOUTH);
        mainFrame.add(label, BorderLayout.NORTH);
        mainFrame.add(panel, BorderLayout.CENTER);

        // 设置主窗口可见
        mainFrame.setVisible(true);
    }

    private static JComboBox<String> createFontComboBox() {
        String[] fonts = GraphicsEnvironment.getLocalGraphicsEnvironment().getAvailableFontFamilyNames();
        JComboBox<String> comboBox = new JComboBox<>(fonts);
        return comboBox;
    }

    private static void changeLabelFont(String selectedFont) {
        label.setFont(new Font(selectedFont, Font.PLAIN, (int) fontSizeSpinner.getValue()));
    }
}
