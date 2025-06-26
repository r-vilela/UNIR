package model;

public interface Pokemon{
    int bonus = 2;
    double debuff = 0.5;

    String getTipo();

    String avaliar();

    String getQualidade();

    double getAtaque();

    double getDefesa();

}
