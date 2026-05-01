package SEM2.oops_lab.endsemfin;
import java.util.Scanner;

class Employeem{
    private int empNum;
    private double empSalary;
    Employeem(int num, double sal){
        this.empNum = num;
        this.empSalary = sal;
    }
    static Employeem getEmployeeData(Scanner sc){
        int n = sc.nextInt();
        double s = sc.nextDouble();
        Employeem e = new Employeem(n,s);
        return e;
    }
    void display(){
        System.out.println("Emp ID: "+empNum+" | Emp Salary: "+empSalary);
    }
}
public class fin14 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Employeem e1 = Employeem.getEmployeeData(sc);
        e1.display();
        sc.close();
    }
}
