
public interface Relatorio {

	void exibirInformacoes();

	default void metodoLivre() {
		System.out.println("Você está livre!");
	}

}
