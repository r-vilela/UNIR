package model;

import javax.swing.table.AbstractTableModel;

import java.util.ArrayList;

public class ProductTableModel extends AbstractTableModel{

    private String[] columns = {"Name", "ID", "Price", "Category"};
    private ArrayList<Product> products = new ArrayList<>();

    public ProductTableModel(ArrayList<Product> products){
        this.columns = columns;
    }

    @Override
    public int getRowCount(){
        return products.size();
    }

    @Override
    public int getColumnCount(){
        return columns.length;
    }

    @Override
    public Object getValueAt(int rowIndex, int columnIndex){
        Product product = products.get(rowIndex);
        switch (columnIndex){
            case 0:
                return product.getName();
            case 1:
                return product.getId();
            case 2:
                return product.getPrice();
            case 3:
                return product.getCat();
            default:
                return null;
        }
    }

    @Override
    public String getColumnName(int column){
        return columns[column];
    }

    public void addProduct(Product product){
        this.products.add(product);
        fireTableRowsInserted(products.size() - 1, products.size() -1);
    }

    public int searchProduct(String name){
        for (int i = 0; i < products.size(); i++){
            if(products.get(i).getName().equalsIgnoreCase(name)){
                return i;
            }
        }
        return -1;
    }

    public void deleteProduct(int index){
        if(index >= 0 && index < products.size()){
            this.products.remove(index);
            fireTableRowsDeleted(index, index);
        }
    }
}
