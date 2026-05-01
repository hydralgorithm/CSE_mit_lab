package SEM2.oops_lab.endsemfin;

interface Research{
    double incentive();
}
class Employee{
    String EmpName;
    int EmpID;
    double basic;
    Employee(String n, int id, double basic){
        this.EmpName = n;
        this.EmpID = id;
        this.basic = basic;
    }
}
class Researcher extends Employee implements Research{
    double DA, HRA;
    int ResearchPoints;
    Researcher(String n, int id, double basic, int resPoints){
        super(n, id, basic);
        this.ResearchPoints = resPoints;
        this.DA = 0.1*basic;
        this.HRA = 0.15*basic;
    }
    public double incentive(){
        return ResearchPoints*1000;
    }
    void TotalPay(){
        double totalPay = basic + DA + HRA + incentive();
        System.out.println("Total Pay = Rs"+totalPay);
    }

}
public class fin13 {
    public static void main(String[] args){
        Researcher r = new Researcher("Bobi", 101, 32000, 76);
        r.TotalPay();
    }
}
