package com.example.pokeapp;

public class PokeType {

    private String name;
    private String url;

    public PokeType(String name, String url){
        this.name = name;
        this.url = url;
    }

    public String getName() {
        return name;
    }

    public String getUrl(){return url;}
}
