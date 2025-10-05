package com.example.pokeapp;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.bumptech.glide.Glide;

import java.util.ArrayList;

public class Adapter extends RecyclerView.Adapter<Adapter.MyViewHolder> {
    private ArrayList<PokeInfo> pokes;

    private onItemClickListener listener;

    public interface onItemClickListener{
        void onItemClick(int position);
        void onItemLongClick(int position);
    }

    public void setOnItemClickListener(onItemClickListener listener){
        this.listener = listener;
    }

    public Adapter(ArrayList<PokeInfo> pokes){
        this.pokes = pokes;
    }

    @NonNull
    @Override
    public MyViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View itemLista = LayoutInflater.from(parent.getContext())
                .inflate(R.layout.layout_items, parent, false);
        return new MyViewHolder(itemLista);
    }

    @Override
    public void onBindViewHolder(@NonNull MyViewHolder holder, int position) {
        //holder.imgPokemon.setImageResource(this.pokes.get(position).getImage());
        holder.txtName.setText(this.pokes.get(position).getName());
        this.pokes.get(position).setImage(img -> {
            Glide.with(holder.itemView.getContext())
                    .load(img)
                    .into(holder.imgPokemon);
        });
    }

    @Override
    public int getItemCount() {
        return pokes.size();
    }

    class MyViewHolder extends RecyclerView.ViewHolder{
        private TextView txtName;
        private ImageView imgPokemon;

        public MyViewHolder (View itemView){
            super(itemView);
            txtName = itemView.findViewById(R.id.txtName);
            imgPokemon = itemView.findViewById(R.id.imgPokemon);
            itemView.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    if(listener != null) {
                        int position = getAbsoluteAdapterPosition();
                        if(position != RecyclerView.NO_POSITION){
                            listener.onItemClick(position);
                        }

                    }
                }
            });
            itemView.setOnLongClickListener(new View.OnLongClickListener() {
                @Override
                public boolean onLongClick(View v) {
                    if(listener != null){
                        int position = getAbsoluteAdapterPosition();
                        if(position != RecyclerView.NO_POSITION){
                            listener.onItemLongClick(position);
                            return true;
                        }
                    }
                    return false;
                }
            });
        }

    }
}
