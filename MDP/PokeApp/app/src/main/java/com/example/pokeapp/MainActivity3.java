package com.example.pokeapp;

import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.widget.LinearLayout;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;
import androidx.recyclerview.widget.DividerItemDecoration;
import androidx.recyclerview.widget.GridLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.google.gson.Gson;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

public class MainActivity3 extends AppCompatActivity {

    private RecyclerView pokeRecycle;
    private Adapter adapter;
    private SharedPreferences preferences;
    private ArrayList<PokeInfo> pokes;
    private static final String PREF_NOME = "favorite_pokemons";
    private static final String PREF_KEY = "favorite";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main3);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });

        pokeRecycle = findViewById(R.id.pokeRecycle);
        this.pokes = new ArrayList<>();
        this.adapter = new Adapter(this.pokes);

        preferences = getSharedPreferences(PREF_NOME, MODE_PRIVATE);

        RecyclerView.LayoutManager layoutManager = new GridLayoutManager(getApplicationContext(), 2);
        //RecyclerView.LayoutManager layoutManager = new LinearLayoutManager(getApplicationContext());
        pokeRecycle.setLayoutManager(layoutManager);
        pokeRecycle.setHasFixedSize(true);
        pokeRecycle.addItemDecoration(new DividerItemDecoration(getApplicationContext(), LinearLayout.VERTICAL));
        this.pokeRecycle.setAdapter(this.adapter);

        Set<String> defValues = new HashSet<>();
        Set<String> favSet = preferences.getStringSet(PREF_KEY,defValues);

        Gson gson = new Gson();
        for(String pokeStr : favSet){
            PokeInfo poke = gson.fromJson(pokeStr, PokeInfo.class);
            pokes.add(poke);
            adapter.notifyDataSetChanged();
        }

        adapter.setOnItemClickListener(new Adapter.onItemClickListener() {
            @Override
            public void onItemClick(int position) {
                Intent intent = new Intent(MainActivity3.this, MainActivity2.class);
                intent.putExtra("name", pokes.get(position).getName());
                intent.putExtra("url", pokes.get(position).getUrl());
                intent.putExtra("id", pokes.get(position).getId());
                intent.putExtra("weight", pokes.get(position).getWeight());
                intent.putExtra("height", pokes.get(position).getHeight());
                intent.putExtra("image", pokes.get(position).getImg());
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
}