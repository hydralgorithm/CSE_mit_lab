class Employeea{
    String name;
    int eId;
    double basic;
    Employeea(String n, int id, double b){
        this.name = n;
        this.eId = id;
        this.basic = b;
    }
    double calculateSalary(){
        double da = 0.52*basic;
        double gross = basic + da;
        double it = 0.30*gross;
        return gross-it;
    }
    void displayEmployeeDetails(){
        System.out.println("Name: " + name+" | Emp ID: "+eId+" | Net salary: Rs"+calculateSalary());
    }
}
class PartTimeEmp extends Employeea{
    int hoursWorked;
    static final double hourlyRate = 250.0;
    PartTimeEmp(String n, int id, int h){
        super(n,id,0);
        this.hoursWorked = h;
    }
    @Override
    double calculateSalary() {
        return hoursWorked*hourlyRate;
    }
    @Override
    void displayEmployeeDetails(){
        System.out.println("PART TIME INFO:");
        System.out.println("Name: "+name+" | Emp ID: "+eId+" | Hours: "+hoursWorked+" | Rate: "+hourlyRate+" | Salary: Rs"+calculateSalary());
    }
}
class FullTimeEmp extends Employeea{
    double bonus, deductions;
    FullTimeEmp(String n, int id,double b, double bonus, double deduction){
        super(n, id, b);
        this.bonus = bonus;
        this.deductions = deduction;
    }
    @Override
    double calculateSalary(){
        double pre = super.calculateSalary();
        return pre - deductions + bonus;
    }
    @Override
    void displayEmployeeDetails(){
        System.out.println("Name: "+name+"| Emp ID: "+eId+" | Net Salary: "+calculateSalary());
    }
}
public class lab7_2 {
    public static void main(String[] args){
        FullTimeEmp ft = new FullTimeEmp("Rahul", 101, 50000, 5000, 2000);
        ft.displayEmployeeDetails();

        System.out.println();

        PartTimeEmp pt = new PartTimeEmp("Sneha", 102, 80);
        pt.displayEmployeeDetails();

        // Dynamic polymorphism
        System.out.println("\n--- Polymorphism Demo ---");
        Employeea e;
        e = new FullTimeEmp("Abdul", 103, 60000, 8000, 1000);
        e.displayEmployeeDetails();
        e = new PartTimeEmp("Divya", 104, 60);
        e.displayEmployeeDetails();
    }
}
