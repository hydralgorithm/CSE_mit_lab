import java.util.Scanner;
import java.util.ArrayList;
class Loan{
    double loanAmt, interestRate;
    int durationYears;
    static int count = 0;
    Loan(double amt, double ir, int dur){
        this.loanAmt = amt;
        this.interestRate = ir;
        this.durationYears = dur;
        count++;
    }
    Loan(double amt){
        this.loanAmt = amt;
        this.interestRate = 0.0; 
        this.durationYears = 0;
        count++;
    }
    void updateLoanIR(double ir){
        this.interestRate = ir;
    }
    void display(){
        System.out.println("Loan Amount: "+loanAmt);
        System.out.println("Interest Rate: "+interestRate);
        System.out.println("Duration: "+durationYears);
    }
    static void displayCount(){
        System.out.println("Total loan applications created: "+count);
    }
}
class bankOfficer{
    String name;
    ArrayList<Loan> appliedLoans = new ArrayList<>();
    bankOfficer(String n){
        this.name = n;
    }
    void assignLoans(Loan l){
        appliedLoans.add(l);
    }
    void display(){
        System.out.println("Name: "+name);
        System.out.println("Assigned Applications: ");
        for(Loan l : appliedLoans){
            l.display();
            System.out.println();
        }
    }
}
public class loanProcess {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        // a)
        Loan l1 = new Loan(10000,0.08,3);
        l1.display();
        System.out.println();
        // b)
        l1.updateLoanIR(0.067);
        l1.display();
        System.out.println();
        // c)
        Loan l2 = new Loan(25000,0.67,2);
        l2.display();
        Loan l3 = new Loan(67000);
        l3.display();
        Loan.displayCount();
        System.out.println();
        // d)
        ArrayList<Loan> loans = new ArrayList<>();
        System.out.println("Enter num of loans to assign: ");
        int n = sc.nextInt();
        for(int i=0; i<n; i++){
            System.out.print("Loan Amt: ");
            double amt = sc.nextDouble();
            System.out.print("Interest Rate: ");
            double ir = sc.nextDouble();
            System.out.print("Duration: ");
            int dur = sc.nextInt();
            loans.add(new Loan(amt,ir,dur));
            for(Loan l : loans){
                l.display();
                System.out.println();
            }
        }
        // e)
        bankOfficer f = new bankOfficer("Jamie");
        f.assignLoans(l1);
        f.assignLoans(l2);
        f.assignLoans(l3);
        f.display();

        sc.close();
    }
}
