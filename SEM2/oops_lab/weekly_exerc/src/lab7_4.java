class Account{
    String cname;
    int accNo;
    String accType;
    double balance;
    Account(String n, int an, String acType, double bal){
        this.cname = n;
        this.accNo = an;
        this.accType = acType;
        this.balance = bal;
    }
    void deposit(double amt){
        balance += amt;
        System.out.println("Deposited: "+amt+" | Balance: "+balance);
    }
    void display(){
        System.out.println("Name: "+cname+" | Acc no.: "+accNo);
        System.out.println("Acc Type: "+accType+" | Balance: "+balance);
    }
    void withdraw(double amt) {
        if (amt > balance) {
            System.out.println("Insufficient funds.");
            return;
        }
        balance -= amt;
        System.out.println("Withdrawn: " + amt + " | Balance: " + balance);
    }
}
class SavingsAccount extends Account{
    static final double INTEREST_RATE = 0.04;
    static final double MIN_BALANCE = 1000;
    static final double PENALTY = 100;
    SavingsAccount(String n, int an, double bal){
        super(n, an, "Savings", bal);
    }
    void computeInterest(){
        double interest = balance*INTEREST_RATE;
        balance += interest;
        System.out.println("Interest added: "+interest+" | Balance: "+balance);
    }
    @Override
    void withdraw(double amt){
        if(amt>balance){
            System.out.println("Insufficient balance! Transaction Denied!");
            return;
        } 
        balance -= amt;
        System.out.println("Withdrawn: "+amt+" | Balance: "+balance);
        if(balance<MIN_BALANCE){
            balance -= PENALTY;
            System.out.println("Balance below minimum. Penalty imposed. Current Balance: "+balance);
        }
    }
}
class CurrentAccount extends Account{
    static final double SERVICE_TAX = 200;
    static final double MIN_BALANCE = 5000;
    CurrentAccount(String n, int accnum, double bal){
        super(n, accnum, "Current", bal);
    }
    @Override
    void withdraw(double amt){
        if(amt>balance){
            System.out.println("Insufficient funds!");
            return;
        }
        balance -= amt;
        System.out.println("Withdrawn: "+amt+" | Balance: "+balance);
        if(balance<MIN_BALANCE){
            balance -= SERVICE_TAX;
            System.out.println("Balance below minimum. Tax imposed. Current Balance: "+balance);
        }
    }
}
public class lab7_4 {
    public static void main(String[] args){
        System.out.println("--SAVINGS ACCOUNT--");
        SavingsAccount sa = new SavingsAccount("Boby Lee", 101, 6500);
        sa.deposit(300);
        sa.withdraw(7000);
        sa.withdraw(6000);
        sa.computeInterest();
        System.out.println("--CURRENT ACCOUNT--");
        CurrentAccount ca = new CurrentAccount("Ben Dover", 102, 5500);
        ca.deposit(67);
        ca.withdraw(3300);
    }
}
