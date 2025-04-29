public final class FixedAccount extends BankAccount{
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
        double value = this.getBalance();
        double temp = value * 0.5;

        value += (temp * mes);

        System.out.printf("Interest for %s months: %.2f\n", mes, value);

    }
}
