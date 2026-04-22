class Eemployee{
    String ename;
    int salary;
    Department[] departments;
    int count = 0;
    Eemployee(String n,int s){
        this.departments = new Department[5];
        this.ename = n;
        this.salary = s;
    }
    class Department{
        String deptName, loc;
        void setDept(String dn, String l){
            this.deptName = dn;
            this.loc = l;
        }
        void deptDisplay(){
            System.out.println("Department: "+deptName+" | Location: "+loc);
        }
    }
    void addDepartment(String dn, String l){
        departments[count] = new Department();
        departments[count].setDept(dn,l);
        count++;
    }
    void displayDetails(){
        System.out.println("Employee Name: "+ename+"\nSalary: "+salary);
        for(int i=0; i<count;i++){
            departments[i].deptDisplay();
        }
    }
}

public class pract5_2 {
    public static void main(String[] args){
        Eemployee e = new Eemployee("Bobby",25000);
        e.addDepartment("Tech","Bengaluru");
        e.addDepartment("Fashion", "Mumbai");
        e.addDepartment("Linux", "Ben Dover");
        e.displayDetails(); 
    }
}
