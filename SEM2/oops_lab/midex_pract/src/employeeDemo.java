class Employee{
    long empID;
    String empName;
    double basic_salary;
    double netSalary;
    Employee(long id, String n, double bs){
        empID = id;
        empName = n;
        basic_salary = bs;
    }
    void computeNetSalary(){
        netSalary = ((basic_salary*0.4) + basic_salary) - (basic_salary + (basic_salary * 0.4))*0.1; 
    }
    void displayDetails(){
        System.out.println("Emp name: "+empName);
        System.out.println("Emp ID: "+empID);
        System.out.println("Basic sal: "+basic_salary);
        System.out.println("Net sal: "+netSalary);
    }
}

public class employeeDemo {
    public static void main(String args[]){
        Employee e1 = new Employee(123, "Bobby",34367);
        Employee e2 = new Employee(153, "Mobby",50000);
        e1.computeNetSalary();
        e2.computeNetSalary();
        e1.displayDetails();
        e2.displayDetails();
    }
}
