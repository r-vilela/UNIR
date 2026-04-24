package model;

public class ProdutoEletronico extends Produto {
  private int mesesGarantia;

  public ProdutoEletronico(String codigo, String nome, int quantidade, double preco) {
    super(codigo, nome, quantidade, preco);
    this.mesesGarantia = 0;
  }

  public ProdutoEletronico(String codigo, String nome, int quantidade, double preco,
      int mesesGarantia) {
    super(codigo, nome, quantidade, preco);
    this.mesesGarantia = mesesGarantia;
  }

  @Override
  public String exibirDetalhes() {
    StringBuilder detalhes = new StringBuilder("\n====== Produto Eletronico ======");
    detalhes.append("\n\tCodigo: ");
    detalhes.append(this.getCodigo());
    detalhes.append("\n\tNome: ");
    detalhes.append(this.getNome());
    detalhes.append("\n\tQuantidade: ");
    detalhes.append(this.getQuantidade());
    detalhes.append("\n\tPreco: R$");
    detalhes.append(this.getPreco());
    detalhes.append("\n\tGarantia: ");
    detalhes.append(this.mesesGarantia);
    if (possuiGarantiaEstendida()) {
      detalhes.append(" + 2 (Garantia Estendida!)");
    }

    return detalhes.toString();
  }

  private boolean possuiGarantiaEstendida() {
    return this.mesesGarantia > 6;
  }

}
