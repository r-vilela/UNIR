package com.example.pokeapp;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;
import androidx.recyclerview.widget.DividerItemDecoration;
import androidx.recyclerview.widget.GridLayoutManager;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.google.android.material.textfield.TextInputEditText;

import java.lang.annotation.Retention;
import java.util.ArrayList;
import java.util.List;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;
import retrofit2.Retrofit;
import retrofit2.converter.gson.GsonConverterFactory;

public class MainActivity extends AppCompatActivity {

    private TextInputEditText edtTipo;
    private Button btnPesquisar;
    private RecyclerView recyclerView;
    private ArrayList<PokeInfo> pokes;
    private Adapter adapter;
    private Retrofit retrofit;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });
        this.edtTipo = findViewById(R.id.edtTipo);
        this.btnPesquisar = findViewById(R.id.btnPesquisar);
        this.pokes = new ArrayList<>();
        this.adapter = new Adapter(this.pokes);

        this.recyclerView = findViewById(R.id.recyclerView);
        //RecyclerView.LayoutManager layoutManager = new GridLayoutManager(getApplicationContext(), 2);
        RecyclerView.LayoutManager layoutManager = new LinearLayoutManager(getApplicationContext());
        recyclerView.setLayoutManager(layoutManager);
        recyclerView.setHasFixedSize(true);
        recyclerView.addItemDecoration(new DividerItemDecoration(getApplicationContext(), LinearLayout.VERTICAL));
        this.recyclerView.setAdapter(this.adapter);

        String url = "https://pokeapi.co/api/v2/";
        retrofit = new Retrofit.Builder()
                .baseUrl(url)
                .addConverterFactory(GsonConverterFactory.create())
                .build();

        btnPesquisar.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(!edtTipo.getText().toString().isEmpty()){
                    String type = edtTipo.getText().toString();
                    //System.out.println(url+"/type/"+type);
                    //PokeType poke = new PokeType(edtTipo.getText().toString());
                    //pokes.add(poke);
                    //adapter.notifyDataSetChanged();
                    //edtTipo.setText("");
                    buscarTipoPokemon(type);
                }
            }
        });

        adapter.setOnItemClickListener(new Adapter.onItemClickListener() {
            @Override
            public void onItemClick(int position) {
                Intent intent = new Intent(MainActivity.this, MainActivity2.class);
                intent.putExtra("name", pokes.get(position).getName());
                intent.putExtra("url", pokes.get(position).getUrl());
                startActivity(intent);
                // Toast.makeText(MainActivity.this, pokes.get(position).getName(), Toast.LENGTH_SHORT).show();
            }
            @Override
            public void onItemLongClick(int position){
                //Toast.makeText(MainActivity.this, "Removido " + pokes.get(position).getName(), Toast.LENGTH_SHORT).show();
                //pokes.remove(position);
                //adapter.notifyDataSetChanged();
            }

        });

    }

    private void buscarTipoPokemon(String type){
        PokeApi pokeApi = retrofit.create(PokeApi.class);
        Call<PokeResponse> call = pokeApi.buscarTipoPokemon(type);
        call.enqueue(new Callback<PokeResponse>() {
            @Override
            public void onResponse(Call<PokeResponse> call, Response<PokeResponse> response) {
                if(response.isSuccessful()){
                    List<PokeType> resultado = response.body().getPokemon();
                    pokes.clear();
                    for(PokeType info : resultado){
                        pokes.add(info.getPokemon());
                    }
                    //pokes.addAll(resultado);
                    adapter.notifyDataSetChanged();
                }else{
                    Toast.makeText(MainActivity.this, "Tipo de Pokemon nao encontrado!", Toast.LENGTH_SHORT).show();
                }
            }

            @Override
            public void onFailure(Call<PokeResponse> call, Throwable t) {
                Toast.makeText(MainActivity.this, "Erro ao buscar tipo de pokemon", Toast.LENGTH_SHORT).show();
            }
        });
    }
}