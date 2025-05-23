
public class Diretor extends Usuario{

	private String titulacao;

	public Diretor(String nome, String matricula, String cpf, int idade, String curso,
			String campus, String titulacao) {
		super(nome, matricula, cpf, idade, curso,  campus);
		this.titulacao = titulacao;
	}

	@Override
	public double calculaSalario(double horas, double horaAula) {
		double salario = horas*horaAula;

		if (this.titulacao.equalsIgnoreCase("especialização")) {
			salario = (salario * 0.10) + salario;
		}
		if (this.titulacao.equalsIgnoreCase("mestrado")) {
			salario = (salario * 0.20) + salario;
		}
		if (this.titulacao.equalsIgnoreCase("doutorado")) {
			salario = (salario * 0.40) + salario;
		}
		return salario;
	}

	public double calculaSalario() {
		return 0;
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
