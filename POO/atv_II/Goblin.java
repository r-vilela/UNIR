public class Goblin extends Monster{

    public Goblin(int level){
        super(level);
    }

    public Goblin(String name, int level){
        super(name, level);
    }

    public String getName(){
        return super.getName();
    }

    public int getLevel(){
        return super.getLevel();
    }

    @Override
    public int calculatePoints(){
        return Multiplier.calculatePoint(this.getLevel(), Multiplier.goblin);

    }

    @Override
    public String roar(){
        return "Goblin says: UUHHAAAA!";
    }

}
