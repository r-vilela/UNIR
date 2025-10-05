package com.example.pokeapp;

import android.widget.Toast;

import java.util.function.Consumer;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;
import retrofit2.Retrofit;
import retrofit2.converter.gson.GsonConverterFactory;

public class PokeInfo {
    private String name;
    private String url;
    private String img;
    private Retrofit retrofit;

    public String getName() {
        return name;
    }

    public void setImage(Consumer<String> callback) {
        System.out.println("SetImage foi chamado");
        callback.accept("https://via.placeholder.com/150");
        retrofit = new Retrofit.Builder()
                .baseUrl(this.url.substring(0,26))
                .addConverterFactory(GsonConverterFactory.create())
                .build();


        PokeApi pokeApi = retrofit.create(PokeApi.class);
        Call<PokeResponse> call = pokeApi.buscarImage(this.url.substring(26));
        call.enqueue(new Callback<PokeResponse>() {
            @Override
            public void onResponse(Call<PokeResponse> call, Response<PokeResponse> response) {
                img = response.body().getSprites().getFront_default();
                callback.accept(img);
            }

            @Override
            public void onFailure(Call<PokeResponse> call, Throwable t) {
                System.out.println("Erro ao baixar imagem do pokemon!");
            }
        });
    }

    public String getUrl() {
        return url;
    }

    public String getImg(){
        return this.img;
    }
}
