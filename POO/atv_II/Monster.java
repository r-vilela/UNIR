public abstract class Monster{
    private String name;
    private int level;

    public Monster(int level){
        this.level = level;
        this.name = "Monster";

    }

    public Monster(String name, int level){
        this.name = name;
        this.level = level;

    }

    public String getName(){
        return this.name;
    }

    public int getLevel(){
        return this.level;
    }

    abstract int calculatePoints();

    abstract String roar();
}
