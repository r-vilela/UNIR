public class Main{
    public static void main(String args[]){

        Player plr = new Player("Vilela");

        Goblin gbl = new Goblin("Goblin", 10);
        System.out.println("\n" + gbl.roar());
        plr.defeatMonster(gbl);

        System.out.println("Now the player " + plr.getName() + " has " + plr.getPoints() + " points!");


        Troll trl = new Troll("Troll", 10);
        System.out.println("\n" + trl.roar());
        plr.defeatMonster(trl);

        System.out.println("Now the player " + plr.getName() + " has " + plr.getPoints() + " points!");



        Dragon drg = new Dragon( "Dragon", 10);
        System.out.println("\n" + drg.roar());
        plr.defeatMonster(drg);

        System.out.println("Now the player " + plr.getName() + " has " + plr.getPoints() + " points!");


    }
}
