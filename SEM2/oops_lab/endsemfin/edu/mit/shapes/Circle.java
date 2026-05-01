package SEM2.oops_lab.endsemfin.edu.mit.shapes;

public class Circle implements Shape{
    private double radius;
    public Circle(double r){
        this.radius = r;
    }
    public double area(){
        return 3.14*radius*radius;
    }
}
