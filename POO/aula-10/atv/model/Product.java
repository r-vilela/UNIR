package model;

public class Product{
    private String id;
    private String name;
    private String price;
    private String category;

    public Product(String name, String id, String price, String category){
        this.id = id;
        this.name = name;
        this.price = price;
        this.category = category;

    }

    public void setId(String id){
        this.id = id;
    }
    public void setName(String name){
        this.name = name;
    }
    public void setPrice(String price){
        this.price = price;
    }
    public void setCat(String cat){
        this.category = cat;
    }

    public String getName(){
        return this.name;
    }
    public String getId(){
        return this.id;
    }
    public String getPrice(){
        return this.price;
    }
    public String getCat(){
        return this.category;
    }
}
