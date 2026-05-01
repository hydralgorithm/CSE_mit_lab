package SEM2.oops_lab.endsemfin;
import java.util.Scanner;

class Employeec{
    int empNum;
    double empSal;
    Employeec(int num, double sal){
        this.empNum = num;
        this.empSal = sal;
    }
    void display(){
        System.out.println("Emp Num: "+empNum+" | Emp Salary: "+empSal);
    }
}
public class fin17 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Employeec[] employeecs = new Employeec[4];
        for(int i=0; i<employeecs.length; i++){
            int num = sc.nextInt();
            double sal = sc.nextDouble();
            employeecs[i] = new Employeec(num, sal);
        }
        System.out.println("Length of Employee array: "+employeecs.length);
        for(Employeec e: employeecs){
            e.display();
        }
        sc.close();
    }
}
