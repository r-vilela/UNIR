public class Troll extends Monster{

    public Troll(int level){
        super(level);
    }

    public Troll(String name, int level){
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
        return Multiplier.calculatePoint(this.getLevel(), Multiplier.troll);

    }

    @Override
    public String roar(){
        return "Troll says: GGGRRRRRRRRR!";
    }

}
