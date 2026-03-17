import java.util.Scanner;

class Employee{
    String Ename;
    int Eid;
    double Basic, DA, Gross_sal, Net_sal;
    void read(Scanner sc){
        sc.nextLine(); // Consume the leftover newline character
        System.out.print("Enter emp name: ");
        this.Ename = sc.nextLine();
        System.out.print("Enter emp id: ");
        this.Eid = sc.nextInt();
        System.out.print("Enter Basic salary: ");
        this.Basic = sc.nextDouble();
    }
    void display(){
        System.out.println("ID: "+Eid+" | Name: "+Ename+" | Basic: Rs"+Basic+"Net Salary: Rs"+Net_sal);
    }
    void compute_net_sal(){
        DA = 0.52 * Basic;
        Gross_sal = Basic + DA;
        double IT = 0.3* Gross_sal;
        Net_sal = Gross_sal - IT;
    }
}

public class lab3_2 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of employees: ");
        int num = sc.nextInt();
        Employee[] employees = new Employee[num];
        for(int i=0; i < num; i++){
            System.out.println("Enter details of Employee "+(i+1)+" : ");
            employees[i] = new Employee(); // Initialize the object!
            employees[i].read(sc);
            employees[i].compute_net_sal();
        }
        sc.close();
        System.out.println();
        System.out.println("Employee Details:");
        for(int i=0; i<num; i++){
            employees[i].display();
        }
    }
}
