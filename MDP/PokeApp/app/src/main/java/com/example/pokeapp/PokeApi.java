package com.example.pokeapp;

import java.util.List;

import retrofit2.Call;
import retrofit2.http.GET;
import retrofit2.http.Path;

public interface PokeApi {
    @GET("type/{type}/")
    Call<TypeResponse> buscarTipoPokemon(@Path("type") String type);

    @GET("{id}")
    Call<PokeResponse> buscarImage(@Path("id") String id);
}
