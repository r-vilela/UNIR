package com.example.pokeapp;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.google.android.material.textfield.TextInputEditText;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    private TextInputEditText edtTipo;
    private Button btnPesquisar;
    private RecyclerView recyclerView;
    private ArrayList<PokeType> pokes;
    private Adapter adapter;

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
        this.recyclerView = findViewById(R.id.recyclerView);
        this.pokes = new ArrayList<>();
        this.adapter = new Adapter(this.pokes);
        RecyclerView.LayoutManager layoutManager = new LinearLayoutManager(getApplicationContext());
        recyclerView.setLayoutManager(layoutManager);

        this.recyclerView.setAdapter(this.adapter);

        btnPesquisar.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                PokeType poke = new PokeType(edtTipo.getText().toString(), edtTipo.getText().toString());
                pokes.add(poke);
                System.out.println(pokes);
                adapter.notifyDataSetChanged();
                edtTipo.setText("");
            }
        });
    }
}