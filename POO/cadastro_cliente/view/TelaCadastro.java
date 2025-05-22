package view;

import java.util.ArrayList;

import model.Client;
import model.ClientTableModel;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.table.DefaultTableModel;

public class TelaCadastro extends JFrame{

    private JPanel cnttPanel;
    private JTextField txtName;
    private JTextField txtEmail;
    private JTextField txtTel;
    private JTextField txtBuscar;
    private JTable tbl;

    public static void main(String[] args){
        EventQueue.invokeLater(new Runnable() {

            public void run() {
                try {
                    TelaCadastro frame = new TelaCadastro();
                    frame.setVisible(true);
                } catch(Exception e) {
                    e.printStackTrace();
                }
            }

        });

    }

    public TelaCadastro(){
        setResizable(false);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBounds(157, 50, 1040, 692);

        //Content Panel
        cnttPanel = new JPanel();
        cnttPanel.setBackground(new Color(255, 255, 255));
        // How it works??
        cnttPanel.setBorder(new EmptyBorder(5, 5, 5, 5));

        setContentPane(cnttPanel);
        cnttPanel.setLayout(null);

        // Title Label
        JLabel ttlLabel = new JLabel("Register Clients");
        ttlLabel.setFont(new Font("LM Sans 10", Font.BOLD, 28));
        ttlLabel.setBounds(470, 40, 438, 66);
        cnttPanel.add(ttlLabel);

        // Setting customer Icon
        ImageIcon cstIcon = new ImageIcon(TelaCadastro.class.getResource("/img/customer-service.png"));

        Image cstImg = cstIcon.getImage();
        Image rszCstImage = cstImg.getScaledInstance(115, 84, Image.SCALE_SMOOTH);
        ImageIcon rszCstIcon = new ImageIcon(rszCstImage);

        // Adding customer Icon Label
        JLabel cstIconLbl = new JLabel("");
        cstIconLbl.setHorizontalAlignment(SwingConstants.CENTER);
        cstIconLbl.setIcon(rszCstIcon);
        cstIconLbl.setBounds(330, 20, 115, 84);
        cnttPanel.add(cstIconLbl);

        // Background panel
        JPanel panel = new JPanel();
        panel.setBounds(30, 136, 979, 184);
        cnttPanel.add(panel);
        panel.setLayout(null);

        // Name Label and Input
        JLabel lblName = new JLabel("Name");
        lblName.setFont(new Font("Dialog", Font.BOLD, 15));
        lblName.setBounds(12, 12, 84, 17);
        panel.add(lblName);

        txtName = new JTextField();
        txtName.setBounds(12, 41, 536, 42);
        panel.add(txtName);
        txtName.setColumns(10);

        // Email Label and Input
        JLabel lblEmail = new JLabel("Email");
        lblEmail.setFont(new Font("Dialog", Font.BOLD, 15));
        lblEmail.setBounds(12, 114, 84, 17);
        panel.add(lblEmail);

        txtEmail = new JTextField();
        txtEmail.setBounds(12, 130, 536, 42);
        panel.add(txtEmail);
        txtEmail.setColumns(10);

        // Telefone Label and Input
        JLabel lblTel = new JLabel("Telefone");
        lblTel.setFont(new Font("Dialog", Font.BOLD, 15));
        lblTel.setBounds(586, 12, 175, 17);
        panel.add(lblTel);

        txtTel = new JTextField();
        txtTel.setBounds(586, 41, 381, 42);
        panel.add(txtTel);
        txtTel.setColumns(10);

        // Genere Radio Panel
        JPanel radioPnl = new JPanel();
        radioPnl.setBackground(new Color(255, 255, 255));
        radioPnl.setBounds(584, 130, 383, 42);
        panel.add(radioPnl);
        radioPnl.setLayout(null);

        // Genere Radio Button
        JRadioButton rdbtnMsc = new JRadioButton("Masculine");
        rdbtnMsc.setFont(new Font("Dialog", Font.BOLD, 15));
        rdbtnMsc.setBackground(new Color(255, 255, 255));
        rdbtnMsc.setBounds(8, 0, 151, 42);
        radioPnl.add(rdbtnMsc);

        JRadioButton rdbtnFem = new JRadioButton("Feminine");
        rdbtnFem.setFont(new Font("Dialog", Font.BOLD, 15));
        rdbtnFem.setBackground(new Color(255, 255, 255));
        rdbtnFem.setBounds(211, 0, 164, 42);
        radioPnl.add(rdbtnFem);

        ButtonGroup btnGrp = new ButtonGroup();
        btnGrp.add(rdbtnMsc);
        btnGrp.add(rdbtnFem);

        JLabel lblGen = new JLabel("Genere");
        lblGen.setFont(new Font("Dialog", Font.BOLD,15));
        lblGen.setBounds(586, 104, 60, 17);
        panel.add(lblGen);


        // Action Buttons Panel
        JPanel actPnl = new JPanel();
        actPnl.setBounds(30, 332, 979, 66);
        cnttPanel.add(actPnl);
        actPnl.setLayout(null);


        // Tabel Panel
        JPanel tblPnl = new JPanel();
        tblPnl.setBounds(30, 410, 979, 237);
        cnttPanel.add(tblPnl);
        tblPnl.setLayout(null);

        JScrollPane tblScrollPnl = new JScrollPane();
        tblScrollPnl.setBounds(12, 12, 955, 213);
        tblPnl.add(tblScrollPnl);

        // Setting up table

        // Table Model
        ArrayList<Client> clients = new ArrayList<>();
        ClientTableModel model = new ClientTableModel(clients);
        model.addClient(new Client("Maria", "maria@unir.br", "Feminine", "1234-1234"));

        tbl = new JTable();
        tbl.setFont(new Font("Dialog", Font.PLAIN, 15));
        tbl.setModel(model);
        tblScrollPnl.setViewportView(tbl);

        JButton saveBtn = new JButton("Save");
        saveBtn.setFont(new Font("Dialog", Font.BOLD, 15));
        saveBtn.setBounds(12, 12, 105, 42);
        actPnl.add(saveBtn);

        JButton delBtn = new JButton("Delete");
        delBtn.setFont(new Font("Dialog", Font.BOLD, 15));
        delBtn.setBounds(157, 12, 105, 42);
        actPnl.add(delBtn);

        JButton srcBtn = new JButton("Search");
        srcBtn.setFont(new Font("Dialog", Font.BOLD, 15));
        srcBtn.setBounds(297, 12, 105, 42);
        actPnl.add(srcBtn);

        txtBuscar = new JTextField();
        txtBuscar.setBounds(427, 12, 540, 42);
        actPnl.add(txtBuscar);
        txtBuscar.setColumns(10);

    }
}

