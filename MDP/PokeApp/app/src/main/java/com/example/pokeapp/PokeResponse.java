package com.example.pokeapp;

import java.util.List;

import retrofit2.Retrofit;

public class PokeResponse {
    private PokeSprite sprites;
    private String weight;
    private String height;
    private String id;

    public String getWeight() {
        return weight;
    }

    public String getHeight() {
        return height;
    }

    public String getId() {
        return id;
    }


    public PokeSprite getSprites() {
        return sprites;
    }

}
