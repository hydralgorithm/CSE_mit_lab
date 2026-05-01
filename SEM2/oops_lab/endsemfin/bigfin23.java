package SEM2.oops_lab.endsemfin;

interface Resizable{
    void resize(double factor);
}
interface Printable{
    void print();
}
class Circle implements Resizable, Printable{
    private double radius;
    Circle(double r){
        this.radius = r;
    }
    @Override
    public void resize(double f){
        this.radius = f*radius;
    }
    @Override
    public void print(){
        System.out.println("Radius: "+this.radius);
    }
}
class Rectangle implements Resizable, Printable{
    double length, width;
    Rectangle(double l, double w){
        this.length = l;
        this.width = w;
    }
    @Override
    public void resize(double f){
        this.length = length*f;
        this.width = width*f;
    }
    @Override
    public void print(){
        System.out.println("Length: "+this.length+" | Width: "+this.width);
    }
}
public class bigfin23 {
    public static void main(String[] args){
        Resizable[] resizables = {
            new Circle(20),
            new Rectangle(20, 5)
        };

        resizables[0].resize(0.5);
        resizables[1].resize(1.5);

        Printable[] printables = {
            (Printable) resizables[0],  // cast same object
            (Printable) resizables[1]
        };

        printables[0].print();  // prints resized values
        printables[1].print();
    }
}
