import java.time.LocalDate;

public class Funcionario extends PessoaFisica{
		private String registro;
		private String carteiraTrabalho;
		private String pis;

		public Funcionario(String nome, String cpf, String email, String telefone, LocalDate dataNascimento, String registro, String carteiraTrabalho, String pis){
				super(nome, cpf, email, telefone, dataNascimento);
				this.registro = registro;
				this.carteiraTrabalho = carteiraTrabalho;
				this.pis = pis;

		}

		public void exibirDados(){
				super.exibirDados();
				System.out.print("\nRegistro: " + this.registro);
				System.out.print("\nCarteira de Trabalho: " + this.carteiraTrabalho);
				System.out.print("\nPIS: " + this.pis);
		}

}
