public class CheckingAccount extends BankAccount{

    public CheckingAccount(){
        super();
    }

    public void deposit(double value){
        super.deposit(value);
    }

    public void withdraw(double value){
        super.withdraw(value);
    }

    public double getBalance(){
        return super.getBalance();
    }

    public void calculateInterest(int mes){
        System.out.println("There is no interest for this account");
    }
}
