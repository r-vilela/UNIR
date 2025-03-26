public class Main{

		public static void main(String[] args){

				Contato c1 = new Contato("Maria", 123345, "maria@gmail.com");
				Contato c2 = new Contato("Mariana", 123345, "maria@gmail.com");
				Contato c3 = new Contato("Marizete", 123345, "maria@gmail.com");

				Agenda.adicionarContato(c1);
				Agenda.adicionarContato(c3);
				Agenda.adicionarContato(c2);

				c1.setNome("Jose");
				Agenda.atualizarContato("Maria", c1); 
				Agenda.removerContato("Jose");
				System.out.println(Agenda.listarContato());
		}

		
}
