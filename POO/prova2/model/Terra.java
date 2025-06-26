package model;

public class Terra extends Normal{
    // Pokemon do tipo terra
    private String qualidade = "Tanka mais";

    public Terra(String nome, double ataque, double defesa) throws AtributoInvalidoException{
        super(nome, ataque, defesa);
    };

    @Override
    public String getTipo(){
        return "Terra";
    };

    @Override
    public String getQualidade(){
        return this.qualidade;
    };

    public String getNome(){
        return super.getNome();
    };

    @Override
    public String avaliar(){
        if(this.ataque > this.defesa){
            return "Ruim: Deu dano e morreu";
        } else if(this.defesa > this.ataque){
            return "Otimo: Demorou mas ganhou";
        } else {
            return "Bom: tem que tankar mais";
        }
    };

    @Override
    public double getAtaque(){
        return super.ataque / Pokemon.debuff;
    };

    @Override
    public double getDefesa(){
        return super.defesa * Pokemon.bonus;
    };

}
