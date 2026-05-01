package SEM2.oops_lab.endsemfin;
abstract class Emmployee{
    private String name;
    private int empId;
    Emmployee(String n, int id){
        this.empId = id;
        this.name = n;
    }
    abstract double computePay();
    void display(){
        System.out.println("Emp id: "+empId+" | Name: "+name+" | Salary: "+computePay());
    }
}
class SalariedEmployee extends Emmployee{
    double weeklySalary;
    SalariedEmployee(String n, int id, double s){
        super(n,id);
        this.weeklySalary =s;
    }
    @Override
    double computePay() { 
        return weeklySalary;
    }
}
class HourlyEmployee extends Emmployee{
    double hourlyRate, hoursworked;
    HourlyEmployee(String n, int id, double hr, double hw){
        super(n,id);
        this.hourlyRate = hr;
        this.hoursworked = hw;
    }
    @Override
    double computePay(){
        if(hoursworked<=40){
            return hourlyRate*hoursworked;
        }
        return (40*hourlyRate) + (hoursworked-40)*hourlyRate*1.5;
    }
}
class CommissionEmployee extends Emmployee{
    double baseSal, sales;
    CommissionEmployee(String n, int id, double b, double sale){
        super(n,id);
        this.baseSal = b;
        this.sales = sale;
    }
    @Override
    double computePay(){
        return baseSal + 0.1*sales;
    }
}
public class bigfin20 {
    public static void main(String[] args){
        Emmployee[] employees = {
            new SalariedEmployee("Bobi", 101, 11000),
            new HourlyEmployee("Lee", 102, 4.2, 45),
            new CommissionEmployee("Bendover", 103, 11000, 56)
        };

        for(Emmployee e : employees){
            e.display();
        }
    }
}
