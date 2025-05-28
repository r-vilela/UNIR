package view;

import javax.swing.*;
import java.awt.*;
import javax.swing.border.EmptyBorder;

import model.Product;
import model.ProductTableModel;

import java.util.ArrayList;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class CadastroProduto extends JFrame{

    private JPanel cnt;
    private JTextField txtName;
    private JTextField txtId;
    private JTextField txtPrice;
    private JTextField txtSearch;
    private JTable tbl;

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

        txtName= new JTextField();
        txtName.setBounds(20, 80, 350, 25);
        txtName.setBackground(new Color(240, 240, 240));
        pnl.add(txtName);
        txtName.setColumns(10);

        // Product ID Label and Input
        JLabel lblID = new JLabel("Product ID");
        lblID.setFont(new Font("Dialog", Font.BOLD, 15));
        lblID.setBounds(20, 120, 200, 20);
        lblID.setForeground(new Color( 15, 15, 15));
        pnl.add(lblID);

        txtId = new JTextField();
        txtId.setBounds(20, 140, 100, 25);
        txtId.setBackground(new Color(240, 240, 240));
        pnl.add(txtId);
        txtId.setColumns(10);

        // Product Price Label and Input
        JLabel lblProdPric = new JLabel("Price");
        lblProdPric.setFont(new Font("Dialog", Font.BOLD, 15));
        lblProdPric.setBounds( 268, 120, 200, 20);
        lblProdPric.setForeground(new Color( 15, 15, 15));
        pnl.add(lblProdPric);

        txtPrice = new JTextField();
        txtPrice.setBounds(269, 140, 100, 25);
        txtPrice.setBackground(new Color(240, 240, 240));
        pnl.add(txtPrice);
        txtPrice.setColumns(10);

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
        tblPnl.setBounds(40, 360, 960, 300);
        tblPnl.setForeground(new Color( 190, 190, 190));
        cnt.add(tblPnl);
        tblPnl.setLayout(null);

        JLabel lblTbl = new JLabel("Product Table");
        lblTbl.setFont(new Font("Dialog", Font.BOLD, 20));
        lblTbl.setBounds( 20, 20, 200, 20);
        lblTbl.setForeground(new Color(39, 200, 47));
        tblPnl.add(lblTbl);

        JScrollPane tblScrollPnl = new JScrollPane();
        tblScrollPnl.setBounds(12, 52, 940, 240);
        tblPnl.add(tblScrollPnl);

        // Table Model
        ArrayList<Product> products = new ArrayList<>();
        ProductTableModel model = new ProductTableModel(products);
        model.addProduct(new Product("KitKat", "10012", "12.99", "Food"));

        tbl = new JTable();
        tbl.setFont(new Font("Dialog", Font.BOLD, 15));
        tbl.setModel(model);
        tblScrollPnl.setViewportView(tbl);

        // Search Field
        JLabel lblSearch = new JLabel("Search:");
        lblSearch.setFont(new Font("Dialog", Font.BOLD, 17));
        lblSearch.setBounds( 470, 18, 63, 20);
        lblSearch.setForeground(new Color( 15, 15, 15));
        tblPnl.add(lblSearch);

        txtSearch = new JTextField();
        txtSearch.setBounds(540, 14, 160, 25);
        txtSearch.setBackground(new Color(240, 240, 240));
        tblPnl.add(txtSearch);
        txtSearch.setColumns(10);

        // Search Button
        JButton searchBtn = new JButton("Search");
        searchBtn.setFont(new Font("Dialog", Font.BOLD, 15));
        searchBtn.setBounds(710, 13, 100, 27);
        searchBtn.setBackground(new Color(60, 180, 230));
        searchBtn.setForeground(Color.white);
        tblPnl.add(searchBtn);

        // Delete Button
        JButton deleteBtn = new JButton("Delete");
        deleteBtn.setFont(new Font("Dialog", Font.BOLD, 15));
        deleteBtn.setBounds(830, 13, 100, 27);
        deleteBtn.setBackground(new Color(230, 70, 60));
        deleteBtn.setForeground(Color.white);
        tblPnl.add(deleteBtn);

        // Buttons Actions
        // Save Button Action
        saveBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent arg0){
                String name = txtName.getText().toString();
                String price = txtPrice.getText().toString();
                String id = txtId.getText().toString();
                String category = rdbtnCatFood.isSelected() ? "Food" : (rdbtnCatClean.isSelected() ? "Cleaning" : "Hygiene");

                if(name.isEmpty() || price.isEmpty() || id.isEmpty()){
                    JOptionPane.showMessageDialog(CadastroProduto.this,
                            "Fill all fields to add a product!",
                            "Alert Message!", JOptionPane.WARNING_MESSAGE);
                }else if(isNum(price) && isNum(id)){
                    Product product = new Product(name, id, price, category);
                    model.addProduct(product);
                }else{
                    JOptionPane.showMessageDialog(CadastroProduto.this,
                            "Make that the id and price fields are numeric!",
                            "Alert Message!", JOptionPane.WARNING_MESSAGE);
                }
            }
        });

        // Delete Button
        deleteBtn.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent arg0){
                int line = tbl.getSelectedRow();
                model.deleteProduct(line);
            }
        });

        searchBtn.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent arg0){
                String name = txtSearch.getText().toString();
                if(!name.isEmpty()){
                    int index = model.searchProduct(name);
                    tbl.setRowSelectionInterval(index, index);
                }else{
                    JOptionPane.showMessageDialog(CadastroProduto.this, "Search text field is empty",
                            "Alert Message!", JOptionPane.WARNING_MESSAGE);
                }
            }
        });

    }

    public static boolean isNum(String txt){
        try{
            Double.parseDouble(txt);
            return true;
        }catch(Exception err){
            return false;
        }
    }



}
