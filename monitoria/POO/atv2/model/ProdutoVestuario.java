package model;

public class ProdutoVestuario extends Produto {
  private String tamanho;
  private String material;

  public ProdutoVestuario(String codigo, String nome, int quantidade, double preco, String tamanho, String material) {
    super(codigo, nome, quantidade, preco);
    this.tamanho = tamanho;
    this.material = material;
  }

  @Override
  public String exibirDetalhes() {
    StringBuilder detalhes = new StringBuilder("\n====== Produto Vestuario ======");
    detalhes.append("\n\tCodigo: ");
    detalhes.append(this.getCodigo());
    detalhes.append("\n\tNome: ");
    detalhes.append(this.getNome());
    detalhes.append("\n\tQuantidade: ");
    detalhes.append(this.getQuantidade());
    detalhes.append("\n\tPreco: R$");
    detalhes.append(this.getPreco());
    detalhes.append("\n\tTamanho: ");
    detalhes.append(this.getTamanho());
    detalhes.append("\n\tMaterial: ");
    detalhes.append(this.getMaterial());

    return detalhes.toString();
  }

  public String getTamanho() {
    return this.tamanho;
  }

  public String getMaterial() {
    return this.material;
  }

}
