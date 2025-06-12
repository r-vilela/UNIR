package view;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class CalculatorFrame extends JFrame{

    private JPanel cnttPanel;
    private JTextField txtRadius;
    private JTextField txtBase;
    private JTextField txtHeight;
    private JTextField txtSide;


    public static void main(String[] args){
        EventQueue.invokeLater(new Runnable() {

            public void run() {
                try {
                    CalculatorFrame frame = new CalculatorFrame();
                    frame.setVisible(true);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });
    }

    public CalculatorFrame(){
        setResizable(false);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBounds(157, 50, 1040, 692);

        JMenuBar mnBar = new JMenuBar();
        setJMenuBar(mnBar);

        JMenu mnHistory = new JMenu("History");
        mnBar.add(mnHistory);

        JMenuItem mnSave = new JMenuItem("Save history");
        mnHistory.add(mnSave);

        JMenuItem mnLoad = new JMenuItem("Load history");
        mnHistory.add(mnLoad);

        JMenuItem mnExit = new JMenuItem("Exit");
        mnHistory.add(mnExit);

		mnExit.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				System.exit(0);
			}
		});

        JMenuItem mnHelp = new JMenuItem("Help");
        mnBar.add(mnHelp);

        cnttPanel = new JPanel();
        cnttPanel.setBackground(new Color(255, 255, 255));
        cnttPanel.setBorder(new EmptyBorder(5, 5, 5, 5));

        setContentPane(cnttPanel);
        cnttPanel.setLayout(null);

		JLabel lblNewLabel = new JLabel("Geometry Calculator");
		lblNewLabel.setFont(new Font("LM Sans 10", Font.BOLD, 28));
		lblNewLabel.setBounds(375, 58, 438, 66);
		cnttPanel.add(lblNewLabel);

        JPanel pnlForms = new JPanel();
		pnlForms.setBounds(150, 150, 750, 400);
		pnlForms.setBackground(new Color(180, 180, 180));
        pnlForms.setLayout(null);
        cnttPanel.add(pnlForms);

		JRadioButton rdbtnCircle = new JRadioButton("Circle");
		rdbtnCircle.setSelected(true);
		rdbtnCircle.setFont(new Font("Dialog", Font.BOLD, 15));
		rdbtnCircle.setBounds(8, 10, 200, 40);
		pnlForms.add(rdbtnCircle);

		JRadioButton rdbtnRect = new JRadioButton("Rectangle");
		rdbtnRect.setFont(new Font("Dialog", Font.BOLD, 15));
		rdbtnRect.setBounds(8, 60, 200, 40);
		pnlForms.add(rdbtnRect);

		JRadioButton rdbtnSquare = new JRadioButton("Square");
		rdbtnSquare.setFont(new Font("Dialog", Font.BOLD, 15));
		rdbtnSquare.setBounds(8, 110, 200, 40);
		pnlForms.add(rdbtnSquare);

		JRadioButton rdbtnTrian = new JRadioButton("Triangle Rectangle");
		rdbtnTrian.setFont(new Font("Dialog", Font.BOLD, 15));
		rdbtnTrian.setBounds(8, 160, 200, 40);
		pnlForms.add(rdbtnTrian);

        ButtonGroup btnGroup = new ButtonGroup();
        btnGroup.add(rdbtnTrian);
        btnGroup.add(rdbtnRect);
        btnGroup.add(rdbtnSquare);
        btnGroup.add(rdbtnCircle);

        JLabel lblRadius = new JLabel("Radius: ");
        lblRadius.setBounds(250, 20, 80, 20);
        lblRadius.setFont(new Font("Dialog", Font.BOLD, 15));

        txtRadius = new JTextField();
        txtRadius.setBounds(250, 40, 80, 20);
        txtRadius.setColumns(10);

        rdbtnCircle.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent arg0){
                txtRadius.setEnabled(true);
                txtSide.setEnabled(false);
                txtHeight.setEnabled(false);
                txtBase.setEnabled(false);

            }
        });

        pnlForms.add(lblRadius);
        pnlForms.add(txtRadius);

        JLabel lblSide = new JLabel("Side: ");
        lblSide.setBounds(250, 65, 80, 20);
        lblSide.setFont(new Font("Dialog", Font.BOLD, 15));

        txtSide = new JTextField();
        txtSide.setBounds(250, 85, 80, 20);
        txtSide.setColumns(10);
        txtSide.setEnabled(false);

        rdbtnSquare.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent arg0){
                txtRadius.setEnabled(false);
                txtSide.setEnabled(true);
                txtHeight.setEnabled(false);
                txtBase.setEnabled(false);

            }
        });

        pnlForms.add(lblSide);
        pnlForms.add(txtSide);

        JLabel lblBase = new JLabel("Base: ");
        lblBase.setBounds(250, 110, 80, 20);
        lblBase.setFont(new Font("Dialog", Font.BOLD, 15));

        txtBase = new JTextField();
        txtBase.setBounds(250, 130, 80, 20);
        txtBase.setColumns(10);
        txtBase.setEnabled(false);

        pnlForms.add(lblBase);
        pnlForms.add(txtBase);

        JLabel lblHeight = new JLabel("Height: ");
        lblHeight.setBounds(250, 155, 80, 20);
        lblHeight.setFont(new Font("Dialog", Font.BOLD, 15));

        txtHeight = new JTextField();
        txtHeight.setBounds(250, 175, 80, 20);
        txtHeight.setColumns(10);
        txtHeight.setEnabled(false);
        txtHeight.setEnabled(false);

        pnlForms.add(lblHeight);
        pnlForms.add(txtHeight);

        rdbtnTrian.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent arg0){
                txtRadius.setEnabled(false);
                txtSide.setEnabled(false);
                txtHeight.setEnabled(true);
                txtBase.setEnabled(true);

            }
        });

        rdbtnRect.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent arg0){
                txtRadius.setEnabled(false);
                txtSide.setEnabled(false);
                txtHeight.setEnabled(true);
                txtBase.setEnabled(true);

            }
        });

    }
}
