package model;

import java.util.ArrayList;
import java.util.List;

public class MainTest{
    public static void main(String[] args) {
        List<Normal> pokemons = new ArrayList<>();

        try {
            pokemons.add(new Normal("Pidgey", 5, 4));
            pokemons.add(new Eletrico("Pikachu", 4, 6));
            pokemons.add(new Terra("Trecko", 3, 2));

            System.out.println("\nTentando criar um pokemon invalido");
            pokemons.add(new Normal("Charmander", -1,0));
        } catch (AtributoInvalidoException e) {
            //TODO: handle exception
            System.err.println("Erro ao criar um pokemon: " + e.getMessage());
        }

        for(Normal pokemon : pokemons){
            System.out.println("Nome: " + pokemon.getNome());
            System.out.println("Tipo: " + pokemon.getTipo());
            System.out.println("Ataque: " + pokemon.getAtaque());
            System.out.println("Defesa: " + pokemon.getDefesa());
            System.out.println("Qualidade: " + pokemon.getQualidade());
            System.out.println("Avaliacao: " + pokemon.avaliar());

            System.out.println("\n");
        }


    }
}

