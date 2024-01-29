import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;

public class App {

    static String Filename = "1.txt"; // 默认文件名
    static JFrame mainFrame = new JFrame("File Content Editor");
    static JTextArea textArea;
    static JButton openButton;
    static JButton saveButton;

    public static void main(String[] args) {
        textArea = new JTextArea();
        textArea.setEditable(true);

        openButton = new JButton("Open File");
        openButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JFileChooser chooser = new JFileChooser();
                int result = chooser.showOpenDialog(mainFrame);
                if (result == JFileChooser.APPROVE_OPTION) {
                    Filename = chooser.getSelectedFile().getAbsolutePath();
                    try {
                        String content = readFileContent(Filename);
                        textArea.setText(content);
                    } catch (IOException ex) {
                        JOptionPane.showMessageDialog(null, "Error reading file: " + ex.getMessage());
                    }
                }
            }
        });

        saveButton = new JButton("Save");
        saveButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                saveToFile();
            }
        });

        JPanel panel = new JPanel();
        panel.add(new JScrollPane(textArea));
        panel.add(openButton, BorderLayout.NORTH);
        panel.add(saveButton, BorderLayout.SOUTH);

        mainFrame.getContentPane().add(panel);

        mainFrame.setSize(400, 300);
        mainFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        mainFrame.setVisible(true);
    }

    private static void saveToFile() {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(Filename))) {
            writer.write(textArea.getText());
            JOptionPane.showMessageDialog(null, "File saved successfully.");
        } catch (IOException ex) {
            JOptionPane.showMessageDialog(null, "Error saving file: " + ex.getMessage());
            ex.printStackTrace();
        }
    }

    // 保持不变的读取文件内容方法
    private static String readFileContent(String fileName) throws IOException {
        StringBuilder contentBuilder = new StringBuilder();
        BufferedReader reader = new BufferedReader(new FileReader(fileName));
        String line;
        while ((line = reader.readLine()) != null) {
            contentBuilder.append(line).append("\n");
        }
        reader.close();
        return contentBuilder.toString();
    }
}