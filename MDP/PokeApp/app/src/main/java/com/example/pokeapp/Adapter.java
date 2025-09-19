package com.example.pokeapp;

import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;

public class Adapter extends RecyclerView.Adapter<Adapter.MyViewHolder> {

    private ArrayList<Pokemon> pokemons;

    public Adapter(ArrayList<Pokemon> pokemons){
        this.pokemons = pokemons;
    }

    @NonNull
    @Override
    public MyViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        return null;
    }

    @Override
    public void onBindViewHolder(@NonNull MyViewHolder holder, int position) {

    }

    @Override
    public int getItemCount() {
        return 0;
    }

    class MyViewHolder extends RecyclerView.ViewHolder{
        private ImageView imgPokemon;
        private TextView txtName;
        private TextView txtHeight;
        private TextView txtWeight;
        private TextView txtId;

        public MyViewHolder (View itemView){
            super(itemView);
            imgPokemon = itemView.findViewById(R.id.imgPokemon);
            txtName = itemView.findViewById(R.id.txtName);
            txtHeight = itemView.findViewById(R.id.txtHeight);
            txtWeight = itemView.findViewById(R.id.txtWeight);
            txtId = itemView.findViewById(R.id.txtId);

        }

    }
}
