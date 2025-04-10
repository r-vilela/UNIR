import java.util.HashMap;

public class Disciplina {
	
	private String nomeDisciplina;
	private Professor professor;
	private int codigo;
	private HashMap<Aluno, double[]> notasAlunos;
	
	public Disciplina (String nomeDisciplina, Professor professor, int codigo) {
		this.nomeDisciplina = nomeDisciplina;
		this.professor = professor;
		this.notasAlunos = new HashMap<Aluno, double[]>();		
		professor.adicionarDisciplina(this);
		this.codigo = codigo;
	}
	
	public void adicionarNota(Aluno aluno, double nota1, double nota2) {
		double notas [] = {nota1, nota2};
		notasAlunos.put(aluno, notas);
	}
	
	public void verNotas() {
		for (Aluno aluno : notasAlunos.keySet()) {
			double notas[] = notasAlunos.get(aluno);
			System.out.print("Nome: " + aluno.getNome());
			System.out.print("\tNota 1: " + notas[0]);
			System.out.print("\tNota 2: " + notas[1]);
			double media = calcularMedia(notas[0], notas[1]);
			System.out.print("\tMédia: " + media);
			System.out.println("\tConceito: " + mostrarConceito(media));
			
		}
	}
	
	public double calcularMedia(double n1, double n2) {
		return (n1+n2)/2;
	}
	
	public String mostrarConceito(double media) {
		if (media >= 7 && media <= 10) {
			return "Aprovado";
		}else {
			return "Reprovado";
		}
	}
	
	public void adicionarAluno(Aluno aluno) {
		//double notas[] = {0, 0};
		this.notasAlunos.put(aluno, null);
	}
	
	public double [] getNotas(Aluno aluno) {
		return this.notasAlunos.get(aluno);
	}
	
	public String getNome() {
		return this.nomeDisciplina;
	}
	
	public int getCodigo() {
		return this.codigo;
	}

}
