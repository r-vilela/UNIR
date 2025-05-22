
import java.lang.reflect.Array;
import java.sql.Date;
import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		// Instância de Diretor
		Diretor diretor = new Diretor(
		    "Carlos Silva",          // nome
		    "D001",                  // matrícula
		    "123.456.789-00",        // CPF
		    50,                      // idade
		    "Administração",         // curso

		    "Campus Central",        // campus
		    "Doutorado"    // titulação
		);

		// Instância de Professor
		Professor professor = new Professor(
		    "Ana Costa",             // nome
		    "P123",                  // matrícula
		    "987.654.321-00",        // CPF
		    40,                      // idade
		    "Engenharia de Software", // curso

		    "Campus Tecnologia",     // campus
		    "Mestrado" // titulação
		);

		// Instância de Aluno
		Aluno aluno = new Aluno(
		    "João Pereira",          // nome
		    "A456",                  // matrícula
		    "111.222.333-44",        // CPF
		    20,                      // idade
		    "Ciência da Computação", // curso

		    "Campus Norte",          // campus
		    true                     // é bolsista
		);

		Disciplina disciplina = new Disciplina("POO", professor, 0);

		Disciplina disciplina1 = new Disciplina("Arquitetura", 0);

		ArrayList<Usuario> usuarios = new ArrayList<>();
		usuarios.add(professor);
		usuarios.add(diretor);
		usuarios.add(aluno);

		//for (Usuario usuario : usuarios) {
			//System.out.println("O salario de " + usuario.getNome() + " é: " + usuario.calculaSalario(40, 90));
		//}

		ArrayList<Relatorio> relatorios = new ArrayList<>();
		relatorios.add(aluno);
		relatorios.add(disciplina);


        disciplina.adicionarNota(aluno, 7.0, 6.0);
        disciplina1.adicionarNota(aluno, 8.0, 7.5);

        disciplina1.exibirInformacoes();
        disciplina.exibirInformacoes();





	}

}
