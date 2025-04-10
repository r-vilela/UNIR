public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Aluno aluno1 = new Aluno("Raul", "202515689");
		Escola.matricularAluno(aluno1);
		//Escola.visualizarAlunos();
		Professor professor = new Professor("João");
		Disciplina disciplina = new Disciplina("POO", professor, 0);
		aluno1.realizarMatricula(disciplina);
		//professor.adicionarNota(aluno1, 8, 9, 0);
		//professor.visualizarAluno("POO", aluno1);
		//professor.verNotas();
		aluno1.visualizarHistorico();

	}

}
