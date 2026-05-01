package SEM2.oops_lab.endsemfin;

abstract class Shape{
    int dim1, dim2;
    Shape(int d1, int d2){
        this.dim1 = d1;
        this.dim2 = d2;
    }
    abstract double area();
    void display(){
        System.out.println("Dim1: " + dim1 + " | Dim2: " + dim2);
    }
}
class Rectangle extends Shape{
    Rectangle(int l, int w){
        super(l,w);
    }
    @Override
    double area(){
        return dim1*dim2;
    }
    @Override
    void display(){
        super.display();
        System.out.println("Area: "+area());
    }
}
class Triangle extends Shape{
    Triangle(int b, int h){
        super(b,h);
    }
    @Override
    double area(){
        return 0.5*dim1*dim2;
    }
    void display(){
        super.display();
        System.out.println("Area: "+area());
    }
}
class Square extends Shape{
    Square(int s){
        super(s,s);
    }
    @Override
    double area(){
        return dim1*dim2;
    }
    void display(){
        super.display();
        System.out.println("Area: "+area());
    }
}
public class bigfin21 {
    public static void main(String[] args){
        Shape[] shapes = {
            new Rectangle(4, 5),
            new Triangle(4, 3),
            new Square(5)
        };
        for(Shape s : shapes){
            s.display();
        }
    }
}
