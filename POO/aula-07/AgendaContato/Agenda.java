import java.util.ArrayList;

public class Agenda{
		static ArrayList<Contato> contatos= new ArrayList<>();


		public static void adicionarContato(Contato addContato){
				contatos.add(addContato);
		}
		public static ArrayList<Contato> listarContato(){
				if(!contatos.isEmpty()){
						return contatos;
				}

				return null;

		}
		public static Contato buscarContato(String nome){
				Contato foundContato;

				for(Contato i: contatos){
						if(i.getNome().equals(nome)){
								return i;
						}
				}

				return null;
		}
		public static void removerContato(String nome){

				for(Contato i: contatos){
						if(i.getNome().equals(nome)){
								contatos.remove(i);
								break;
						}

				}
		}
		public static void atualizarContato(String nome, Contato novoContato){

				for(Contato i: contatos){
						if(i.getNome().equals(nome)){
								contatos.set(contatos.indexOf(i), novoContato);
						}
				}
		}
}
