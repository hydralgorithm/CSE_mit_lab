package SEM2.oops_lab.endsemfin;

class Person{
    String name, DoB;
    Person(){
        this.name = "Unknown";
        this.DoB = "Null";
    }
    Person(String n, String Dob){
        this.name = n;
        this.DoB = Dob;
    }
    void displayDetails(){
        System.out.println("Employee Name: "+name+" | DoB: "+DoB );
    }
}
class Employeeb extends Person{
    int empID, Salary, date, month, year;
    Employeeb(){
        this.empID = 0;
        this.date = 0;
        this.month = 0;
        this.year = 0;
        this.Salary = 0;
    }
    Employeeb(int empID, String n, String dob, int d, int m, int y, int sal){
        super(n,dob);
        this.empID = empID;
        this.date = d;
        this.month = m;
        this.year = y;
        this.Salary = sal;
    }
    void displayDetails(){
        super.displayDetails();
        System.out.println("Emp ID: "+empID+" | Emp Name: "+name+" | Emp DoJ: "+date+"-"+month+"-"+year+" | Emp Salary: Rs"+Salary);
    }
    boolean getService(){
        if(year<2016) return true;
        else return false;
    }
}
public class fin5 {
    public static void main(String[] args){
        Employeeb[] employeebs = new Employeeb[3];
        employeebs[0] = new Employeeb(101,"John","12-03-1990",21,4,2021,32000);
        employeebs[1] = new Employeeb(102,"Bobi","11-06-1980",16,2,2011,40000);
        employeebs[2] = new Employeeb(103,"Pam","01-01-2002",2,8,2018,72000);
        employeebs[0].displayDetails();
        employeebs[1].displayDetails();
        employeebs[2].displayDetails();
        for(int i=0; i<3; i++){
            if(employeebs[i].getService()){
                System.out.println("Emp ID: "+employeebs[i].empID+" | Emp Name: "+employeebs[i].name);
            }
        }
    }
}
