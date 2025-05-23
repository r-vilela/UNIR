
import java.util.ArrayList;

public class Professor extends Usuario{

	private ArrayList<Disciplina> disciplinas;
	private String titulacao;

	public Professor(String nome, String matricula, String cpf, int idade, String curso,
			String campus, String titulacao) {
		super(nome, matricula, cpf, idade, curso, campus);
		this.disciplinas = new ArrayList<>();
		this.titulacao = titulacao;
	}

	public void adicionarDisciplina(Disciplina disciplina) {
		this.disciplinas.add(disciplina);
	}

	public void verNotas() {
		for (Disciplina disciplina: disciplinas) {
			System.out.println("Nome Disciplina: " + disciplina.getNome());
			disciplina.exibirInformacoes();
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
	@Override
	public double calculaSalario(double horas, double horaAula) {
		double salario = horas*horaAula;

		if (this.titulacao.equalsIgnoreCase("especialização")) {
			salario = (salario * 0.05) + salario;
		}
		if (this.titulacao.equalsIgnoreCase("mestrado")) {
			salario = (salario * 0.15) + salario;
		}
		if (this.titulacao.equalsIgnoreCase("doutorado")) {
			salario = (salario * 0.30) + salario;
		}
		return salario;
	}

	@Override
	public void exibirInformacoes() {
		// TODO Auto-generated method stub

	}

	@Override
	public void testar() {
		// TODO Auto-generated method stub

	}



}
