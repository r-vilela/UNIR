package model;

import javax.swing.table.AbstractTableModel;

import java.util.ArrayList;

public class ClientTableModel extends AbstractTableModel{

    private String[] columns = {"Name", "Email", "Telefone", "Genere"};
    private ArrayList<Client> clients = new ArrayList<>();

    public ClientTableModel(ArrayList<Client> clients){
        this.clients = clients;
    }

    @Override
    public int getRowCount() {
        return clients.size();
    }

    @Override
    public int getColumnCount() {
        return columns.length;
    }

    @Override
    public Object getValueAt(int rowIndex, int columnIndex) {
        Client client = clients.get(rowIndex);
        switch (columnIndex){
            case 0:
                return client.getName();
            case 1:
                return client.getEmail();
            case 2:
                return client.getTelefone();
            case 3:
                return client.getGenere();
            default:
                return null;
        }
    }

    @Override
    public String getColumnName(int column){
        return columns[column];
    }

    public void addClient(Client client){
        this.clients.add(client);
        fireTableRowsInserted(clients.size() -1, clients.size() -1);
    }

    public int searchClient(String name){
        for (int i = 0 ; i < clients.size(); i++){
            if(clients.get(i).getName().equalsIgnoreCase(name)){
                return i;
            }
        }
        return -1;
    }

    public void deleteClient(int index){
        if (index >= 0 && index < clients.size()){
            this.clients.remove(index);
            fireTableRowsDeleted(index, index);
        }
    }
}
