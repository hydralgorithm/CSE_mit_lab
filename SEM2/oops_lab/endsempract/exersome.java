class InsufficientBalanceException extends Exception{
    public String toString(){
        return "Insufficient Balance! Transaction Failed!";
    }
}
class BankAccountt{
    double balance;
    BankAccountt(double b){
        this.balance = b;
    }
    public void withdraw(int amt){
        try{
            if(amt>balance){
                throw new InsufficientBalanceException();
            } else if(amt < 0){
                throw new IllegalArgumentException("Amount cannot be negative!");
            }
        }catch(InsufficientBalanceException e){
            System.out.println(e);
            return;
        }catch(IllegalArgumentException e){
            System.out.println(e.getMessage());
            return;
        }
        if(amt == 0){
            System.out.println("0 Amount is nothing and hence cannot be withdrawn!");
            return;
        }
        balance -= amt;
        System.out.println("Withdrawn: "+amt+" | Current Balance: "+balance);
        
    }
}

public class exersome {
    public static void main(String[] args){
        BankAccountt b = new BankAccountt(4500);
        b.withdraw(3500);
        // b.withdraw(0);
        // b.withdraw(6000);
        b.withdraw(-300);
    }
}
