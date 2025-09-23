package com.example.pokeapp;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;

public class Adapter extends RecyclerView.Adapter<Adapter.MyViewHolder> {

    private ArrayList<PokeType> pokes;

    public Adapter(ArrayList<PokeType> pokes){
        this.pokes = pokes;
    }

    @NonNull
    @Override
    public MyViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View itemList = LayoutInflater.from(parent.getContext())
                .inflate(R.layout.layout_items,parent,false);
        return new MyViewHolder(itemList);
    }

    @Override
    public void onBindViewHolder(@NonNull MyViewHolder holder, int position) {
        //holder.imgPokemon.setImageResource(this.pokemons.get(position).getImage());
        System.out.println("Positio: "+position);
        holder.txtName.setText(this.pokes.get(position).getName());
    }

    @Override
    public int getItemCount() {
        return pokes.size();
    }

    class MyViewHolder extends RecyclerView.ViewHolder{
        private TextView txtName;

        public MyViewHolder (View itemView){
            super(itemView);
            txtName = itemView.findViewById(R.id.txtName);
        }

    }
}
