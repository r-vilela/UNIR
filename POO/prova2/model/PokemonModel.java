package model;

import javax.swing.table.AbstractTableModel;

import java.util.ArrayList;

public class PokemonModel extends AbstractTableModel{

    private String[] columns = {"Nome", "Tipo", "Ataque", "Defesa", "Qualidade", "Avaliacao"};
    private ArrayList<Normal> pokemons = new ArrayList<>();

    public PokemonModel(ArrayList<Normal> pokemons){
        this.columns = columns;
    }

    @Override
    public int getRowCount(){
        return pokemons.size();
    }

    @Override
    public int getColumnCount(){
        return columns.length;
    }

    @Override
    public Object getValueAt(int rowIndex, int columnIndex){
        Normal pokemon = pokemons.get(rowIndex);
        switch (columnIndex){
            case 0:
                return pokemon.getNome();
            case 1:
                return pokemon.getTipo();
            case 2:
                return pokemon.getAtaque();
            case 3:
                return pokemon.getDefesa();
            case 4:
                return pokemon.getQualidade();
            case 5:
                return pokemon.avaliar();
            default:
                return null;
        }
    }

    @Override
    public String getColumnName(int column){
        return columns[column];
    }

    public void addPokemon(Normal pokemon){
        this.pokemons.add(pokemon);
        fireTableRowsInserted(pokemons.size() - 1, pokemons.size() -1);
    }

    public int searchPokemon(String name){
        for (int i = 0; i < pokemons.size(); i++){
            if(pokemons.get(i).getNome().equalsIgnoreCase(name)){
                return i;
            }
        }
        return -1;
    }

    public void deletePokemon(int index){
        if(index >= 0 && index < pokemons.size()){
            this.pokemons.remove(index);
            fireTableRowsDeleted(index, index);
        }
    }

	public void limparDados() {
		this.pokemons.clear();
		fireTableDataChanged();
	}
}
