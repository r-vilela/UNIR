package com.example.pokeapp;

public class Pokemon {

    private String name;
    private String id;
    private String height;
    private String weight;

    public Pokemon(String name, String id, String height, String weight){
        this.name = name;
        this.id = id;
        this.height = height;
        this.weight = weight;
    }

    public String getId() {
        return this.id;
    }

    public String getHeight() {
        return height;
    }

    public String getName() {
        return name;
    }

    public String getWeight() {
        return weight;
    }
}
