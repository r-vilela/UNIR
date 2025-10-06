package com.example.pokeapp;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
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

public class MainActivity2 extends AppCompatActivity {

    private TextView txtNamePoke;
    private Button btnAPI;
    private String url;
    private TextInputEditText heightTxt;
    private TextInputEditText weightTxt;
    private TextInputEditText idTxt;
    private ImageView pokeImg;



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

        Intent intent = getIntent();
        String namePoke = intent.getStringExtra("name");
        url = intent.getStringExtra("url");
        String idPoke = intent.getStringExtra("id");
        String weightPoke = intent.getStringExtra("weight");
        String heightPoke = intent.getStringExtra("height");
        String imagePoke = intent.getStringExtra("image");

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