package SEM2.oops_lab.endsemfin.edu.mit.shapes;

public class Rectangle implements Shape {
    double len, wid; // default access - package private
    public Rectangle(double l, double w) {
        this.len = l;
        this.wid = w;
    }
    public double area() {
        return len * wid;
    }
}