import java.util.Scanner;

class EMPLOYEE{
    String ename;
    double salary;
    Department[] departments;
    EMPLOYEE(String n, double sal, int count){
        this.ename = n;
        this.salary =sal;
        this.departments = new Department[count];
    }
    void addDepartment(Scanner sc){
        for(int i=0; i < departments.length ;i++){
            System.out.println("Enter details for dept "+(i+1)+" : ");
            System.out.print("Dept name: ");
            String dname = sc.nextLine();
            System.out.print("Enter dept loc: ");
            String dloc = sc.nextLine();
            departments[i] = new Department(dname, dloc);
        }
    }
    void displayAllDetails(){
        System.out.println("Employee Name: "+ename);
        System.out.println("Employee Salary: "+salary);
        for(Department d : departments){
            d.displayDetails();
        }
    }
    class Department{
        String deptName, loc;
        Department(String dept, String locate){
            assign(dept, locate);
        }
        void assign(String dept, String locate){
            this.deptName = dept;
            this.loc = locate;
        }
        void displayDetails(){
            System.out.println("Depatment Name: "+deptName+" | Location: "+loc);
        }
    }
}
public class lab5_2 {
    public static void main(String[] args){
        EMPLOYEE e = new EMPLOYEE("Bob Lee", 67000, 3);
        Scanner s = new Scanner(System.in);
        e.addDepartment(s);
        e.displayAllDetails();
        s.close();
    }
}
