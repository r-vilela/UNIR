public class Player{
    private final String name;
    private int points;

    public Player(String name){
        this.name = name;
        this. points = 0;

    }

    public void defeatMonster(Monster m){
        this.points += m.calculatePoints();

        System.out.println("Monster " + m.getName() + " defeated!");

    }

    public int getPoints(){
        return this.points;
    }

    public String getName(){
        return this.name;
    }
}
