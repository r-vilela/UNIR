import model.ProdutoAlimenticio;
import model.ProdutoEletronico;
import model.ProdutoVestuario;

import java.time.LocalDate;

public class Main {
  public static void main(String[] args) {
    ProdutoAlimenticio pa = new ProdutoAlimenticio("ALI1928", "Cenoura", 12, 7.45, LocalDate.now());
    ProdutoEletronico pe1 = new ProdutoEletronico("ELE1947", "Teclado", 12, 12.45);
    ProdutoEletronico pe2 = new ProdutoEletronico("ELE1926", "Mouse", 9, 10.95, 3);
    ProdutoEletronico pe3 = new ProdutoEletronico("ELE1926", "Monitor", 6, 32.95, 7);
    ProdutoVestuario pv = new ProdutoVestuario("VES1954", "Vestido", 13, 27.75, "M", "Algodao");

    System.out.println(pa.exibirDetalhes());
    // System.out.println(pe1.exibirDetalhes());
    // System.out.println(pe2.exibirDetalhes());
    System.out.println(pe3.exibirDetalhes());
    System.out.println(pv.exibirDetalhes());
  }
}
