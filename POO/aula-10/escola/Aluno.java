
import java.util.ArrayList;

public class Aluno extends Usuario {

	private ArrayList<Disciplina> disciplinas;
	private boolean ehBolsista;

	public Aluno(String nome, String matricula, String cpf, int idade, String curso,
			String campus, boolean ehBolsista) {
		super(nome, matricula, cpf, idade, curso, campus );
		this.disciplinas = new ArrayList<>();
		this.ehBolsista = ehBolsista;
	}

	public ArrayList<Disciplina> getDisciplinas() {
		return disciplinas;
	}
	public void setDisciplinas(ArrayList<Disciplina> disciplinas) {
		this.disciplinas = disciplinas;
	}

	public int realizarMatricula(Disciplina disciplina) {
		if (this.disciplinas.size() < 6) {
			if (disciplina.adicionarAluno(this)) {
				this.disciplinas.add(disciplina);
				return 1;
			}else {
				//System.out.println("Você já está matriculado em: " + disciplina.getNome());
				return -1;
			}

		}
		return 0;
	}

	public void exibirInformacoes() {
		System.out.println("Disciplina\tNota 1\tNota 2");
		for (Disciplina disciplina : disciplinas) {
			System.out.print(disciplina.getNome());
			double notas[] = disciplina.getNotas(this);
			if (notas != null) {
				System.out.println("\t" + notas[0] + "\t" + notas[1]);
			}else {
				System.out.println("\nNão há notas registradas!");
			}
		}
	}

	public void visualizarNotaDisciplina(String disciplina) {

		for (Disciplina d : disciplinas) {
			if (d.getNome().equalsIgnoreCase(disciplina)) {
				System.out.println("Nome: " + d.getNome());
				double notas[] = d.getNotas(this);
				if (!notas.equals(null)) {
					System.out.println("Nota 1: " + notas[0] + "|Nota2: " + notas[1]);
				}else {
					System.out.println("Não há notas registradas!");
				}

			}
		}
	}

	public void visualizarNotaDisciplina(int codigo) {
		System.out.println("Disciplina\tNota 1\tNota 2");
		for (Disciplina d : disciplinas) {
			if (d.getCodigo() == codigo) {
				System.out.print(d.getNome());
				double notas[] = d.getNotas(this);
				System.out.println("\t" + notas[0] + "\t" + notas[1]);
			}
		}
	}
	@Override
	public void exibirRelatorio() {
		super.exibirRelatorio();
		System.out.println("Total de disciplinas: " + this.disciplinas.size());
	}

	@Override
	public double calculaSalario(double horas, double horaAula) {
		double salario = 0;

		if (this.ehBolsista) {
			salario = (horas* horaAula);
		}

		return salario;
	}

	@Override
	public void testar() {
		// TODO Auto-generated method stub

	}


}
