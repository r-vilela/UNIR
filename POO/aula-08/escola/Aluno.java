import java.util.ArrayList;

public class Aluno {
	
	private String nome;
	private String matricula;
	private ArrayList<Disciplina> disciplinas;	
	
	public Aluno(String nome, String matricula) {
		this.nome = nome;
		this.matricula = matricula;
		this.disciplinas = new ArrayList<>();
	}
	
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public String getMatricula() {
		return matricula;
	}
	public void setMatricula(String matricula) {
		this.matricula = matricula;
	}
	public ArrayList<Disciplina> getDisciplinas() {
		return disciplinas;
	}
	public void setDisciplinas(ArrayList<Disciplina> disciplinas) {
		this.disciplinas = disciplinas;
	}
	
	public void realizarMatricula(Disciplina disciplina) {
		if (this.disciplinas.size() < 6) {
			this.disciplinas.add(disciplina);
			disciplina.adicionarAluno(this);
		}		
	}
	
	public void visualizarHistorico() {
		for (Disciplina d : disciplinas) {
			System.out.println("Disciplina: " + d.getNome());
			double notas[] = d.getNotas(this);
			if(notas != null) {
				System.out.println("Nota 1: " + notas[0] + "|Nota2: " + notas[1]);
			} else {
				System.out.println("Nao ha notas registradas!");
			}
		}
	}
	
	public void visualizarNotaDisciplina(String disciplina) {
		for (Disciplina d : disciplinas) {
			if (d.getNome().equalsIgnoreCase(disciplina)) {
				System.out.println("Nome: " + d.getNome());
				double notas[] = d.getNotas(this);
				System.out.println("Nota 1: " + notas[0] + "|Nota2: " + notas[1]);
			}
		}
	}
	
	public void visualizarNotaDisciplina(int codigo) {
		for (Disciplina d : disciplinas) {
			if (d.getCodigo() == codigo) {
				System.out.println("Nome: " + d.getNome());
				double notas[] = d.getNotas(this);
				System.out.println("Nota 1: " + notas[0] + "|Nota2: " + notas[1]);
			}
		}
	}
	
	

}
