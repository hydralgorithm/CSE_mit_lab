package SEM2.oops_lab.endsemfin.edu.mit;
import SEM2.oops_lab.endsemfin.edu.mit.shapes.*;

public class shapeDemo {
    public static void main(String[] args){
        Shape s1 = new Circle(25);
        Shape s2 = new Rectangle(4, 6);
        System.out.println("Circle Area: " + s1.area());
        System.out.println("Rectangle Area: " + s2.area());

        // accessing default member from outside package
        // System.out.println(((Rectangle)s2).len);
        // COMPILE ERROR: len has default access, not accessible outside edu.mit.shapes
        
    }
}
