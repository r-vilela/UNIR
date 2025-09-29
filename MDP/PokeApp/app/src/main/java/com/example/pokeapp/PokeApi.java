package com.example.pokeapp;

import java.util.List;

import retrofit2.Call;
import retrofit2.http.GET;
import retrofit2.http.Path;

public interface PokeApi {
    @GET("type/{type}/")
    Call<PokeResponse> buscarTipoPokemon(@Path("type") String type);
}
