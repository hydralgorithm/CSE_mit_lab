package SEM2.oops_lab.endsemfin;

class InsufficientFundsException extends Exception{
    double bal;
    InsufficientFundsException(double bal){
        this.bal = bal;
    }
    public String toString(){
        return "Insufficient balance! Current Balance: "+bal;
    }
}

class BankAccount{
    private int accNo;
    private String holderName;
    private double balance;
    private static double interestRate = 3.5;
    BankAccount(int acno, String n, double bal){
        this.accNo = acno;
        this.holderName = n;
        this.balance = bal;
    }
    static void setInterestRate(double r){
        interestRate = r;
    }
    void deposit(double amt){
        balance += amt;
        System.out.println("Amount deposited. Current balance: "+balance);
    }
    void withdraw(double amt) throws InsufficientFundsException{
        if(balance-amt<500){
            throw new InsufficientFundsException(balance);
        }
        balance -= amt;
        System.out.println("Amount withdrawn. Current balance: "+balance);
    }
    void display(){
        System.out.println("Acc No.: "+accNo+" | Holder Name: "+holderName);
        System.out.println("Balance: Rs"+balance+" | Interest Rate: "+interestRate);
    }
}
public class bigfin18 {
    public static void main(String[] args){
        BankAccount[] bankAccounts = {new BankAccount(101, "Bali", 6700),
            new BankAccount(102, "Riya", 12000),
            new BankAccount(103, "Bobby", 7000)
        };
        BankAccount.setInterestRate(0.5);
        try{
            bankAccounts[0].deposit(4300);
            bankAccounts[1].withdraw(11000);
            bankAccounts[2].display();
            bankAccounts[1].withdraw(700);
        } catch(InsufficientFundsException e){
            System.out.println(e);
        }
    }
}
