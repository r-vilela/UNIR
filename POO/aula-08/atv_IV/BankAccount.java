public abstract class BankAccount implements Account{
    private double balance;

    public BankAccount(){
        this.balance = 0;
    }
    public void deposit(double value){
        this.balance += value;
    };

    public void withdraw(double value){
        this.balance += value;
    };

    public double getBalance(){
        return this.balance;
    };

    abstract void calculateInterest(int mes);
}
