package view;

import javax.swing.*;
import java.awt.*;
import javax.swing.border.EmptyBorder;

public class CadastroProduto extends JFrame{

    private JPanel cnt;

    public static void main(String[] args){
        EventQueue.invokeLater(new Runnable() {

            public void run() {
                try{
                    CadastroProduto frame = new CadastroProduto();
                    frame.setVisible(true);
                } catch(Exception e){
                    e.printStackTrace();
                }
            }
        });
    }

    public CadastroProduto(){

        setResizable(false);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBounds(157, 50, 1040, 692);

        cnt = new JPanel();
        cnt.setBackground(new Color(170, 214, 171));
        cnt.setBorder(new EmptyBorder(5, 5, 5, 5));

        setContentPane(cnt);
        cnt.setLayout(null);

        // Header Panel
        JPanel pnlTtl = new JPanel();
        pnlTtl.setBounds( 0, 0, 1040, 150);
        pnlTtl.setBackground(new Color( 39, 200, 47));
        cnt.add(pnlTtl);
        pnlTtl.setLayout(null);

        // Header Title
        JLabel ttlLabel = new JLabel("Health Store");
        ttlLabel.setFont(new Font("LM Sans 10", Font.BOLD, 30));
        ttlLabel.setBounds(480, 40, 438, 66);
        ttlLabel.setForeground(Color.white);
        pnlTtl.add(ttlLabel);
        ttlLabel.setLayout(null);

        // Header Icon
        ImageIcon icon = new ImageIcon(CadastroProduto.class.getResource("/img/store.png"));

        Image iconImg = icon.getImage();
        Image rszImg = iconImg.getScaledInstance(70, 64, Image.SCALE_SMOOTH);
        ImageIcon rszIcon = new ImageIcon(rszImg);

        JLabel iconLbl = new JLabel("");
        iconLbl.setHorizontalAlignment(SwingConstants.CENTER);
        iconLbl.setIcon(rszIcon);
        iconLbl.setBounds(180, 40, 438, 66);
        pnlTtl.add(iconLbl);

        // Product panel
        JPanel pnl = new JPanel();
        pnl.setBounds( 40, 170, 960, 180);
        pnl.setForeground(new Color( 190, 190, 190));
        cnt.add(pnl);
        pnl.setLayout(null);

        JLabel lblProd = new JLabel("New Product");
        lblProd.setFont(new Font("Dialog", Font.BOLD, 20));
        lblProd.setBounds( 20, 20, 200, 20);
        lblProd.setForeground(new Color(39, 200, 47));
        pnl.add(lblProd);

        // Product Name Label and Input
        JLabel lblProdName = new JLabel("Product Name");
        lblProdName.setFont(new Font("Dialog", Font.BOLD, 15));
        lblProdName.setBounds( 20, 60, 200, 20);
        lblProdName.setForeground(new Color( 15, 15, 15));
        pnl.add(lblProdName);

        JTextField txtProdName= new JTextField();
        txtProdName.setBounds(20, 80, 350, 25);
        txtProdName.setBackground(new Color(240, 240, 240));
        pnl.add(txtProdName);
        txtProdName.setColumns(10);

        // Product ID Label and Input
        JLabel lblProdID = new JLabel("Product ID");
        lblProdID.setFont(new Font("Dialog", Font.BOLD, 15));
        lblProdID.setBounds(20, 120, 200, 20);
        lblProdID.setForeground(new Color( 15, 15, 15));
        pnl.add(lblProdID);

        JTextField txtProdID = new JTextField();
        txtProdID.setBounds(20, 140, 100, 25);
        txtProdID.setBackground(new Color(240, 240, 240));
        pnl.add(txtProdID);
        txtProdID.setColumns(10);

        // Product Price Label and Input
        JLabel lblProdPric = new JLabel("Price");
        lblProdPric.setFont(new Font("Dialog", Font.BOLD, 15));
        lblProdPric.setBounds( 268, 120, 200, 20);
        lblProdPric.setForeground(new Color( 15, 15, 15));
        pnl.add(lblProdPric);

        JTextField txtProdPric = new JTextField();
        txtProdPric.setBounds(269, 140, 100, 25);
        txtProdPric.setBackground(new Color(240, 240, 240));
        pnl.add(txtProdPric);
        txtProdPric.setColumns(10);

        // Product Category Radio
        JLabel lblCat = new JLabel("Category");
        lblCat.setFont(new Font("Dialog", Font.BOLD, 15));
        lblCat.setBounds(520, 60, 200, 20);
        pnl.add(lblCat);

        JRadioButton rdbtnCatFood = new JRadioButton("Food");
        rdbtnCatFood.setFont(new Font("Dialog", Font.BOLD, 15));
        rdbtnCatFood.setBackground(new Color(240, 240, 240));
        rdbtnCatFood.setBounds(530, 85, 80, 20);
        pnl.add(rdbtnCatFood);

        JRadioButton rdbtnCatClean = new JRadioButton("Cleaning");
        rdbtnCatClean.setFont(new Font("Dialog", Font.BOLD, 15));
        rdbtnCatClean.setBackground(new Color(240, 240, 240));
        rdbtnCatClean.setBounds(650, 85, 100, 20);
        pnl.add(rdbtnCatClean);

        JRadioButton rdbtnCatHyg = new JRadioButton("Hygiene");
        rdbtnCatHyg.setFont(new Font("Dialog", Font.BOLD, 15));
        rdbtnCatHyg.setBackground(new Color(240, 240, 240));
        rdbtnCatHyg.setBounds(530, 105, 200, 20);
        pnl.add(rdbtnCatHyg);

        ButtonGroup btnGrp = new ButtonGroup();
        btnGrp.add(rdbtnCatHyg);
        btnGrp.add(rdbtnCatClean);
        btnGrp.add(rdbtnCatFood);

        // Save Button
        JButton saveBtn = new JButton("Add Product");
        saveBtn.setFont(new Font("Dialog", Font.BOLD, 15));
        saveBtn.setBounds(600, 135, 220, 30);
        saveBtn.setBackground(new Color(39, 200, 47));
        saveBtn.setForeground(Color.white);
        pnl.add(saveBtn);

        // Table panel
        JPanel tblPnl = new JPanel();
        tblPnl.setBounds(40, 360, 960, 180);
        tblPnl.setForeground(new Color( 190, 190, 190));
        cnt.add(tblPnl);
        tblPnl.setLayout(null);

        JLabel lblTbl = new JLabel("Product Table");
        lblTbl.setFont(new Font("Dialog", Font.BOLD, 20));
        lblTbl.setBounds( 20, 20, 200, 20);
        lblTbl.setForeground(new Color(39, 200, 47));
        tblPnl.add(lblTbl);

    }

}
