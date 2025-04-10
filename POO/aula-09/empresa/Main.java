import java.time.LocalDate;

public class Main{
		public static void main(String[] args) {
				LocalDate d1 = LocalDate.of(2004, 03, 29);

				System.out.print("Cliente\n");
				Cliente cliente = new Cliente("Amanda", "123.123.123-23", "69 93123-1234", "amandinha@gmail.com", d1, LocalDate.now());
				cliente.exibirDados();

				System.out.print("\n\nFuncionario\n");
				Funcionario  funcionario = new Funcionario("Feliph", "123.123.123-12", "69 91233-2344", "feliphgames@gmail.com" , LocalDate.of(2006, 07, 21), "1237123", "132123123", "322");

				funcionario.exibirDados();
		}
}
