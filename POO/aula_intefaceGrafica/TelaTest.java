package view;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class TelaTest extends JFrame{

    public static void main(String[] args){
        JFrame frame = new JFrame("Tela Cadastro");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(800, 600);

        JMenuBar menu = new JMenuBar();
        JMenu fileMenu = new JMenu("File");
        JMenuItem openitem = new JMenuItem("Open");
        JMenuItem exititem = new JMenuItem("Exit");
        fileMenu.add(openitem);
        fileMenu.addSeparator();
        fileMenu.add(exititem);
        menu.add(fileMenu);

        JPanel panel = new JPanel();
        JButton button = new JButton("Click me!");
        panel.add(button);

        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(frame, "Button Clicked!");
            }
        });

        JPanel textPanel =  new JPanel();
        JLabel label = new JLabel("Geeks for Geeks Premier League!");
        textPanel.add(label);

        frame.setLayout(new BorderLayout());
        frame.setJMenuBar(menu);
        frame.add(panel, BorderLayout.CENTER);
        frame.add(textPanel, BorderLayout.SOUTH);

        frame.setVisible(true);

    }
}
