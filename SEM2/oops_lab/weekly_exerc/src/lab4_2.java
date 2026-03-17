class EMPLOYEE{
    String ename;
    int empid;
    double emp_sal;
    EMPLOYEE(){
        this.ename = "none";
        this.empid = 0;
        this.emp_sal = 0.0; 
    }
    EMPLOYEE(String n, int id, double sal){
        this.ename = n;
        this.empid = id;
        this.emp_sal = sal;
    }
    void display(){
        System.out.println("Emp ID: "+empid);
        System.out.println("Emp Name: "+ename);
        System.out.println("Emp Salary: "+emp_sal);
        System.out.println();
    }
}

public class lab4_2 {
    public static void main(String[] args){
        EMPLOYEE e1 = new EMPLOYEE();
        EMPLOYEE e2 = new EMPLOYEE("Ron",101,34555);
        e1.display();
        e2.display();
    }
}
