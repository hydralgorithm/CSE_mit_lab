abstract class Figure{
    double x,y;
    Figure(double x, double y){
        this.x = x;
        this.y = y;
    }
    abstract double area();
    void display(){
        System.out.println("Dimensions: "+x+"X"+y);
    }
}
class Rectangle extends Figure{
    Rectangle(double l, double b){
        super(l,b);
    }
    @Override
    double area(){
        return x*y;
    }
}
class Triangle extends Figure{
    Triangle(double b, double h){
        super(b,h);
    }
    @Override
    double area(){
        return 0.5*x*y;
    }
}
class Square extends Figure{
    Square(double s){
        super(s,s);
    }
    @Override
    double area(){
        return x*x;
    }
}
public class lab8_1 {
    public static void main(String[] args){
        Rectangle r = new Rectangle(4, 5);
        Triangle t = new Triangle(4, 4);
        Square s = new Square(3);

        System.out.println("Rec area: "+r.area());
        System.out.println("Tri area: "+t.area());
        System.out.println("Sqr area: "+s.area());

        Figure f;
        f = new Rectangle(4, 5);
        System.out.println("Area: " + f.area());
        f = new Triangle(4, 4);
        System.out.println("Area: " + f.area());
        f = new Square(3); 
        System.out.println("Area: " + f.area());
    }
}
