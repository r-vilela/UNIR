package com.example.spinname;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import java.util.Random;

public class MainActivity extends AppCompatActivity {
    private Button btn_sortear;
    private EditText edt_listanomes;
    private TextView txt_resultado;

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
        btn_sortear = findViewById(R.id.btn_Sortear);
        edt_listanomes = findViewById(R.id.edt_ListaNome);
        txt_resultado = findViewById(R.id.txt_resultado);

        btn_sortear.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view){
                    String listaNomes = edt_listanomes.getText().toString();
                    String nomes[] = listaNomes.split(" ");
                    Random random = new Random();
                    int num = random.nextInt(nomes.length);

                    txt_resultado.setText("Resultado: " + nomes[num]);
                };
        }
        );



    }
}