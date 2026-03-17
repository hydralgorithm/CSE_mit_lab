class BankAccount{
    String depName, accntType;
    long accntNum;
    double bal_amount;
    static double ROI = 5.0;
    static final double MIN_BALANCE = 1000.0;
    BankAccount(){
        this.depName = "none";
        this.accntNum = 0;
        this.accntType = "Savings";
        this.bal_amount = 0.0;
    }
    BankAccount(String n, long num, String type, double bal){
        this.depName = n;
        this.accntNum = num;
        this.accntType = type;
        this.bal_amount = bal;
    }
    void deposit(double n){
        bal_amount += n;
        System.out.println("You deposited Rs"+n+" and your current balance is Rs"+bal_amount);
    }
    void withdraw(double n){
        if(n <= 0){
            System.out.println("Withdrawal amount must be positive.");
        } else if((bal_amount - n) < MIN_BALANCE){
            System.out.println("Withdrawal denied. Minimum balance Rs" + MIN_BALANCE + " must be maintained. Current bal = Rs" + bal_amount);
        } else{
            bal_amount -= n;
            System.out.println("You withdrew Rs"+n+" and your current balance is Rs"+bal_amount);
        }
    }
    void displayDetails(){
        System.out.println("Account depositor name: "+depName);
        System.out.println("Account Number: "+accntNum);
        System.out.println("Account Type: "+accntType);
        System.out.println("Current Balance: Rs"+bal_amount);
        System.out.println();
    }
    static void displayROI(){
        System.out.println("ROI is "+ROI+"%");
    }
}

public class lab4_3 {
    public static void main(String[] args){
        BankAccount b1 = new BankAccount();
        b1.displayDetails();
        BankAccount b2 = new BankAccount("Bob",16786,"Deposit",500);
        b2.displayDetails();
        b2.deposit(7000);
        b2.withdraw(1000);
        b2.displayDetails();
        BankAccount.displayROI();
    }
}
