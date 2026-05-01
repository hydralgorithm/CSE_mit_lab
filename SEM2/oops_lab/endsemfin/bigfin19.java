package SEM2.oops_lab.endsemfin;

class Employeef{
    static int count=0;
    int empId;
    String name;
    double salary;
    static{
        System.out.println("Employee system initialized!");
    }
    Employeef(String n, double sal){
        count++;
        this.empId = count;
        this.name = n;
        this.salary = sal;
    }
    void display(){
        System.out.println("emp ID: "+empId+" | Emp Name: "+name);
        System.out.println("Salary: "+salary);
    }
    static int getCount(){
        return count;
    }
}

public class bigfin19 {
    public static void main(String[] args){
        Employeef e1 = new Employeef("Bob", 67000);
        System.out.println(Employeef.getCount());
        Employeef e2 = new Employeef("Lee", 12500);
        Employeef e3 = new Employeef("Joe", 92000);
        System.out.println(Employeef.getCount());
        Employeef e4 = new Employeef("Sam", 45000);
        System.out.println(Employeef.getCount());
        e1.display();
        e2.display();
        e3.display();
        e4.display();
    }
}
