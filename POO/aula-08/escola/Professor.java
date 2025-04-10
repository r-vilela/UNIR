import java.util.ArrayList;

public class Professor {
	
	private String nomeProfessor;
	private ArrayList<Disciplina> disciplinas;
	
	public Professor(String nome) {
		this.nomeProfessor = nome;
		this.disciplinas = new ArrayList<>();
	}
	
	public void adicionarDisciplina(Disciplina disciplina) {
		this.disciplinas.add(disciplina);
	}
	
	public void verNotas() {
		for (Disciplina d: disciplinas) {
			System.out.println("Nome Disciplina: " + d.getNome());
			d.verNotas();
		}
	}
	
	public void visualizarAluno(String nome, Aluno aluno) {
		for (Disciplina d : disciplinas) {
			if (d.getNome().equalsIgnoreCase(nome)) {
				double notas [] = d.getNotas(aluno);
				System.out.println("Nome: " + aluno.getNome());
				System.out.println("Notas: " + notas[0] + " | " + notas[1]);
			}
		}
	}
	
	public void adicionarNota(Aluno aluno, double nota1, double nota2, int cod) {
		for (Disciplina d : disciplinas) {
			if (d.getCodigo() == cod) {
				d.adicionarNota(aluno, nota1, nota2);
				break;
			}
		}
	}

}
