//package mains;

import java.util.ArrayList;

public class ExemploArrayList{	

		public static void main(String[] args) {

				ArrayList<String> lista = new ArrayList<>();

				lista.add("Raul");
				lista.add("Antonio");
				lista.add("Filiph");

				lista.add(3, "Amanda");

				String n = lista.get(2);

				System.out.println(n);

				for (String nome : lista) {
						System.out.println(nome);
				}

				System.out.println("Tamanho da Lista: " + lista.size());

				System.out.println("Esta vazia?" + lista.isEmpty());


				lista.clear();

				System.out.println("Esta vazia?" + lista.isEmpty());

		}
}
