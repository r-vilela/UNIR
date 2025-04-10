import java.util.HashMap;

public class Biblioteca{
		private static int totalEmprestimos;
		private static HashMap<Livro, Aluno> emprestimos = new HashMap<>();

		public static void registrarEmprestimo(){
				totalEmprestimos += 1;
		}

		public static void registrarDevolucao(){
				totalEmprestimos -= 1;
		}

		public static void registrarAlunoComLivro(Aluno aluno, Livro livro){
				emprestimos.put(livro, aluno);
		}

		public static void removerAlunoComLivro(Aluno aluno, Livro livro){
				emprestimos.remove(livro);
		}

		public static void exibirEmprestimos(){
				for ( Livro livro : emprestimos.keySet() ){
						System.out.println("Aluno: " + emprestimos.get(livro).getNome());
						System.out.println("Livros: " + livro.getTitulo());
				}
		}

		public static int exibirTotalEmprestimos(){
				return totalEmprestimos;
		}
}
