public class SavingsAccount extends BankAccount{
    private double interest;

    public SavingsAccount(){
        super();
        this.interest = 0.1;
    };

    public void deposit(double value){
        super.deposit(value);
    };

    public void withdraw(double value){
        super.withdraw(value);
    };

    public double getBalance(){
        return super.getBalance();
    };

    public void calculateInterest(int mes){
        double value = this.getBalance();
        for(int i = 0; i<mes; i++){
            double temp = value * this.interest;
            value += temp;
        }
        System.out.printf("Interest for %s months: %.2f\n", mes, value);
    };

    public void addInterest(double value){
        this.interest = value;
    };
}
