public class Main{
    public static void main(String[] args){
        FixedAccount fix = new FixedAccount();

        fix.deposit(100);

        System.out.println("Fixed Account balance: " + fix.getBalance());
        fix.calculateInterest(12);

        SavingsAccount sav = new SavingsAccount();

        sav.deposit(100);
        sav.withdraw(50);
        sav.addInterest(0.5);

        System.out.println("Savings Account balance: " + sav.getBalance());
        sav.calculateInterest(12);

        CheckingAccount chk = new CheckingAccount();

        chk.deposit(200);
        chk.withdraw(100);

        System.out.println("Checking Account balance: " + chk.getBalance());
        chk.calculateInterest(12);

    };
}
