
public abstract class Usuario implements Relatorio, Aleatoria{

	protected String nome;
	private String matricula;
	private String cpf;
	private int idade;
	private String curso;
	private double salario;
	private String campus;

	public Usuario(String nome, String matricula, String cpf, int idade, String curso,
			String campus) {

		this.nome = nome;
		this.matricula = matricula;
		this.cpf = cpf;
		this.idade = idade;
		this.curso = curso;
		this.campus = campus;
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
	public String getCpf() {
		return cpf;
	}
	public void setCpf(String cpf) {
		this.cpf = cpf;
	}
	public int getIdade() {
		return idade;
	}
	public void setIdade(int idade) {
		this.idade = idade;
	}
	public String getCurso() {
		return curso;
	}
	public void setCurso(String curso) {
		this.curso = curso;
	}

	public void exibirRelatorio() {
		System.out.println("Nome: " + this.nome);
		System.out.println("Idade: " + this.idade);
		System.out.println("Curso: " + this.curso);
		System.out.println("CPF: " + this.cpf);
		System.out.println("Matrícula: " + this.matricula);
	}

	public abstract double calculaSalario(double horas, double horaAula);



}
