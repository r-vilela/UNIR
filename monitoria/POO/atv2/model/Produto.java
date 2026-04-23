package model;

public abstract class Produto {
    private final String codigo;
    private String nome;
    private int quantidade;
    private double preco;
    private static int totalProdutos = 0;

    public Produto(String codigo, String nome, int quantidade, double preco){
        this.codigo = codigo;
        this.nome = nome;
        this.quantidade = quantidade;
        this.preco = preco;

        totalProdutos++;
    }

    private int verificaQuantidade(int quantidade){
        if (quantidade > 0) {
            return 1;
        }
        return 0;
    }

    public final int saidaEstoque(int quantidade){
        int resultado = verificaQuantidade(quantidade);
        if (resultado == 1) {
            if (quantidade > this.quantidade){
                return -1;
            }
            this.quantidade -= quantidade;
            return 1;
        }
        return resultado;
    }

    public final int saidaEstoque(int quantidade, boolean permitirZerar){
        int resultado = verificaQuantidade(quantidade);
        if (resultado == 1) {
            if (quantidade > this.quantidade){
                return -1;
            }
            if(permitirZerar == true){
                this.quantidade -= quantidade;
            }else{
                if((this.quantidade - quantidade) <= 0){
                    return -1;
                }
                this.quantidade -= quantidade;
            }
            return 1;
        }
        return resultado;
    }

    public abstract String exibirDetalhes();

    public final int entradaEstoque(int quantidade){
        int resultado = verificaQuantidade(quantidade);
        if (resultado == 1) {
            this.quantidade += quantidade;
            return 1;
        }
        return resultado;
    }

    public int getQuantidade(){
        return this.quantidade;
    }

    public double getPreco(){
        return this.preco;
    }

    public String getString(){
        return this.codigo;
    }

    public String getNome(){
        return this.nome;
    }

    public static int getTotalProdutos(){
        return Produto.totalProdutos;
    }


}
