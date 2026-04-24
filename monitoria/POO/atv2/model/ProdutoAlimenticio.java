package model;

import java.time.LocalDate;
import java.lang.StringBuilder;

public class ProdutoAlimenticio extends Produto {
  private LocalDate dataValidade;

  public ProdutoAlimenticio(String codigo, String nome, int quantidade, double preco, LocalDate dataValidade) {
    super(codigo, nome, quantidade, preco);
    this.dataValidade = dataValidade;
  }

  @Override
  public String exibirDetalhes() {
    StringBuilder detalhes = new StringBuilder("===== Produto Alimenticio ======\n");
    detalhes.append("\n\tCodigo: ");
    detalhes.append(this.getCodigo());
    detalhes.append("\n\tNome: ");
    detalhes.append(this.getNome());
    detalhes.append("\n\tQuantidade: ");
    detalhes.append(this.getQuantidade());
    detalhes.append("\n\tPreco: R$");
    detalhes.append(this.getPreco());
    detalhes.append("\n\tData validade: ");
    detalhes.append(this.getDataValidade());

    return detalhes.toString();
  }

  @Override
  public int saidaEstoque(int quantidade) {
    if (!estaVencido()) {
      return -1;
    }
    return super.saidaEstoque(quantidade);
  }

  private boolean estaVencido() {
    return dataValidade.isBefore(LocalDate.now());
  }

  public LocalDate getDataValidade() {
    return this.dataValidade;
  }

}
