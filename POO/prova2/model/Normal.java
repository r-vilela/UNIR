package model;

public class Normal implements Pokemon{
    // Pokemon do tipo normal
    protected String nome;
    protected double ataque;
    protected double defesa;
    private String qualidade = "Nenhuma";

    public Normal(String nome, double ataque, double defesa) throws AtributoInvalidoException{
        if(ataque <= 0 || defesa <= 0){
            throw new AtributoInvalidoException("Ataque e Defesa tem que ser maior que 0");
        } else {
            this.nome = nome;
            this.ataque = ataque;
            this.defesa = defesa;
        }
    };

    public String getNome(){
        return this.nome;
    }

    public String getTipo(){
        return "Normal";
    };

    public String getQualidade(){
        return this.qualidade;
    };

    public String avaliar(){
        if(this.ataque > this.defesa){
            return "Bom: Eh para dar dano";
        } else if(this.defesa > this.ataque){
            return "Bom: Eh para tankar";
        } else {
            return "Otimo: Equilibrado";
        }
    };

    public double getAtaque(){
        return this.ataque;
    };

    public double getDefesa(){
        return this.defesa;
    };

}
