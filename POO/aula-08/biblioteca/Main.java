public class Main{
		public static void main(String[] args) {
				Livro livro1 = new Livro("Percy Jackson", "Rick Riordan");
				Livro livro2 = new Livro("Harry Potter", "J. K. Rolling");
				Livro livro3 = new Livro("Romeo e Julieta", "Willian Shakespeare");
				Aluno aluno1 = new Aluno("JP", "2024123");
				Aluno aluno2 = new Aluno("Giovanni", "2024145");
				Aluno aluno3 = new Aluno("Feliph", "2024111");

				//System.out.println(livro);

				aluno1.emprestarLivro(livro2);
				aluno1.emprestarLivro(livro3);
				aluno3.emprestarLivro(livro3);
				aluno2.emprestarLivro(livro1);
				
				//System.out.println(aluno);

				//aluno.devolverLivro(livro);

				//System.out.println(aluno);

				Biblioteca.exibirEmprestimos();

				System.out.println(Biblioteca.exibirTotalEmprestimos());
		}
}
