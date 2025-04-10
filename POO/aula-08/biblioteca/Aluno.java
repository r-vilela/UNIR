import java.util.ArrayList;

public class Aluno{
		
		private String nome;
		private String matricula;
		private ArrayList<Livro> livrosEmprestados;

		public Aluno(String nome, String matricula){
				this.nome = nome;
				this.matricula = matricula;
				this.livrosEmprestados = new ArrayList<Livro>();
		}

		public void emprestarLivro(Livro livro){
				if(livrosEmprestados.size() < 3 && livro.isAvailable()){
						livro.marcarComoEmprestado();
						livrosEmprestados.add(livro);

						Biblioteca.registrarAlunoComLivro(this, livro);
						Biblioteca.registrarEmprestimo();
				}
		}	

		public void devolverLivro(Livro livro){
				if(livrosEmprestados.contains(livro)){
						livrosEmprestados.remove(livro);

						Biblioteca.removerAlunoComLivro(this, livro);
						Biblioteca.registrarDevolucao();
				}
		}

		public String toString(){
				return ("Nome: " + this.nome + 
						"\nMatricula: " + this.matricula +
						"\nLivros Emprestados: " + this.livrosEmprestados);
		}

		public String getNome(){
				return this.nome;
		}

}
