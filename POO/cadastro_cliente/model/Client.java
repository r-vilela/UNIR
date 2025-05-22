package model;

public class Client{
    private String name;
    private String email;
    private String telefone;
    private String genere;

    public Client(String name, String email, String telefone, String genere){
        super();
        this.name = name;
        this.email = email;
        this.telefone = telefone;
        this.genere = genere;
    }

    public String getName(){
        return this.name;
    }
    public String getEmail(){
        return this.email;
    }
    public String getTelefone(){
        return this.telefone;
    }
    public String getGenere(){
        return this.genere;
    }

    public void setName(String name){
        this.name = name;
    }
    public void setEmail(String email){
        this.email = email;
    }
    public void setTelefone(String tel){
        this.telefone = tel;
    }
    public void setGenere(String gen){
        this.genere = gen;
    }

}
