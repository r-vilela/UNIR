import java.util.HashMap;

public class Escola {
	
	private static HashMap<String, Aluno> alunos = new HashMap<>();
	
	public static void matricularAluno(Aluno aluno) {
		if (!alunos.containsKey(aluno.getMatricula())) {
			alunos.put(aluno.getMatricula(), aluno);
		}
	}
	
	public static void visualizarAlunos() {
		for (String mat : alunos.keySet()) {
			System.out.println("Matricula: " + alunos.get(mat).getMatricula());
			System.out.println("Aluno: " + alunos.get(mat).getNome());
		}
	}

}
