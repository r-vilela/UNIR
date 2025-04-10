import java.time.LocalDate;

public class Cliente extends PessoaFisica{
		private LocalDate clienteDesde;

		public Cliente(String cpf, String nome, String email, String telefone, LocalDate dataNascimento, LocalDate clienteDesde){
				super(cpf, nome, email, telefone, dataNascimento);
				this.clienteDesde = clienteDesde;
		}

		@Override
		public void exibirDados(){
				super.exibirDados();
				System.out.print("\nCliente desde: " + this.clienteDesde);
		}
}
