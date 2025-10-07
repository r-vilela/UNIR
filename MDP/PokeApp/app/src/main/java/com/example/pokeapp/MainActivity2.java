package com.example.pokeapp;

import android.content.Intent;
import android.content.SharedPreferences;
import android.net.Uri;
import android.os.Bundle;
import android.os.Parcelable;
import android.view.View;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import com.bumptech.glide.Glide;
import com.google.android.material.textfield.TextInputEditText;
import com.google.gson.Gson;

import java.util.HashSet;
import java.util.Set;

public class MainActivity2 extends AppCompatActivity {

    private TextView txtNamePoke;
    private Button btnAPI;
    private ImageButton favoriteBtn;
    private String url;
    private TextInputEditText heightTxt;
    private TextInputEditText weightTxt;
    private TextInputEditText idTxt;
    private ImageView pokeImg;
    private SharedPreferences preferences;
    private static final String PREF_NOME = "favorite_pokemons";
    private static final String PREF_KEY = "favorite";



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main2);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });

        heightTxt = findViewById(R.id.heightTxt);
        weightTxt = findViewById(R.id.weightTxt);
        idTxt = findViewById(R.id.idTxt);
        txtNamePoke = findViewById(R.id.txtNamePoke);
        btnAPI = findViewById(R.id.btnAPI);
        pokeImg = findViewById(R.id.pokeImg);
        favoriteBtn = findViewById(R.id.favoriteBtn);
        preferences = getSharedPreferences(PREF_NOME, MODE_PRIVATE);

        Intent intent = getIntent();
        String namePoke = intent.getStringExtra("name");
        url = intent.getStringExtra("url");
        String idPoke = intent.getStringExtra("id");
        String weightPoke = intent.getStringExtra("weight");
        String heightPoke = intent.getStringExtra("height");
        String imagePoke = intent.getStringExtra("image");

        Set<String> defValues = new HashSet<>();
        Set<String> favSet = preferences.getStringSet(PREF_KEY,defValues);

        Gson gson = new Gson();
        for(String pokeStr : favSet){
            PokeInfo poke = gson.fromJson(pokeStr, PokeInfo.class);
            if(poke.getId().equals(idPoke)){
                favoriteBtn.setImageResource(R.drawable.heart);
            }
        }

        favoriteBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Gson gson = new Gson();
                SharedPreferences.Editor editor = preferences.edit();
                PokeInfo poke = new PokeInfo(namePoke, idPoke, url, heightPoke, weightPoke, imagePoke);
                String json = gson.toJson(poke);

                favSet.add(json);

                editor.putStringSet(PREF_KEY,favSet);
                editor.apply();
                favoriteBtn.setImageResource(R.drawable.heart);
            }
        });

        txtNamePoke.setText(namePoke);
        heightTxt.setText(heightPoke);
        weightTxt.setText(weightPoke);
        idTxt.setText(idPoke);
        Glide.with(this)
                .load(imagePoke)
                .into(pokeImg);

        btnAPI.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intentAPI = new Intent(Intent.ACTION_VIEW, Uri.parse(url));
                startActivity(intentAPI);
            }
        });

    }
}