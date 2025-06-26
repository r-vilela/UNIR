package model;

public class Eletrico extends Normal{
    // Pokemon do tipo eletrico
    private String qualidade = "Agilidade";

    public Eletrico(String nome, double ataque, double defesa) throws AtributoInvalidoException{
        super(nome, ataque, defesa);
    };

    @Override
    public String getTipo(){
        return "Eletrico";
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
            return "Otimo: Bateu correu";
        } else if(this.defesa > this.ataque){
            return "Ruim: Bateu morreu (muito lento)";
        } else {
            return "Bom: tem que dar mais dano";
        }
    };

    @Override
    public double getAtaque(){
        return super.ataque * Pokemon.bonus;
    };

    @Override
    public double getDefesa(){
        return super.defesa / Pokemon.debuff;
    };

}
