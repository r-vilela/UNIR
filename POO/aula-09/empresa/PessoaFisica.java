import java.time.LocalDate;

public class PessoaFisica{
		private String cpf;
		private String nome;
		private String email;
		private LocalDate dataNascimento;

		public PessoaFisica(String nome, String cpf, String email, String telefone, LocalDate dataNascimento){
				this.cpf = cpf;
				this.nome = nome;
				this.email = email;
				this.dataNascimento = dataNascimento;
		}

		public void exibirDados() {
				System.out.print("Nome: " + this.nome);
				System.out.print("\nCPF: " + this.cpf);
				System.out.print("\nEmail: " + this.email);
				System.out.print("\nData de Nascimento: " + this.dataNascimento);
		}
}
