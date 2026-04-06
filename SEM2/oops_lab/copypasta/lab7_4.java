class Account {
    String name;
    int accNo;
    String type;
    double balance;

    Account(String name, int accNo, String type, double balance) {
        this.name = name;
        this.accNo = accNo;
        this.type = type;
        this.balance = balance;
    }

    void deposit(double amt) {
        balance += amt;
        System.out.println("Deposited: " + amt + " | Balance: " + balance);
    }

    void withdraw(double amt) {
        balance -= amt;
        System.out.println("Withdrawn: " + amt + " | Balance: " + balance);
    }

    void display() {
        System.out.println("Name: " + name + 
        " | Acc: " + accNo + 
        " | Type: " + type + 
        " | Balance: " + balance);
    }
}

class SavingsAccount extends Account {
    static final double INTEREST_RATE = 0.04;
    static final double MIN_BALANCE = 1000.0;

    SavingsAccount(String name, int accNo, double balance) {
        super(name, accNo, "Savings", balance);
    }

    void computeInterest() {
        double interest = balance * INTEREST_RATE;
        balance += interest;
        System.out.println("Interest: " + interest + " | Balance: " + balance);
    }

    @Override
    void withdraw(double amt) {
        if (balance - amt < MIN_BALANCE)
            System.out.println("Cannot withdraw. Min balance required: " + MIN_BALANCE);
        else super.withdraw(amt);
    }
}

class CurrentAccount extends Account {
    static final double MIN_BALANCE = 5000.0;
    static final double PENALTY = 500.0;

    CurrentAccount(String name, int accNo, double balance) {
        super(name, accNo, "Current", balance);
    }

    @Override
    void withdraw(double amt) {
        super.withdraw(amt);
        if (balance < MIN_BALANCE) {
            balance -= PENALTY;
            System.out.println("Penalty imposed. Balance: " + balance);
        }
    }
}

public class lab7_4 {
    public static void main(String[] args) {
        SavingsAccount sa = new SavingsAccount("Alice", 1001, 5000);
        System.out.println("-- Savings Account --");
        sa.display();
        sa.deposit(2000);
        sa.computeInterest();
        sa.withdraw(500);

        CurrentAccount ca = new CurrentAccount("Bob", 1002, 6000);
        System.out.println("\n-- Current Account --");
        ca.display();
        ca.deposit(1000);
        ca.withdraw(3000);
    }
}