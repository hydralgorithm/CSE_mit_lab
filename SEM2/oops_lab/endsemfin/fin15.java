package SEM2.oops_lab.endsemfin;

abstract class Figure{
    int dim1, dim2;
    Figure(int d1, int d2){
        this.dim1 = d1;
        this.dim2 = d2;
    }
    abstract void Area();
}
class Rectangle extends Figure{
    Rectangle(int l, int b){
        super(l,b);
    }
    @Override
    void Area(){
        System.out.println("Area = "+(dim1*dim2));
    }
}
class Triangle extends Figure{
    Triangle(int b, int h){
        super(b,h);
    }
    @Override
    void Area(){
        System.out.println("Area = "+(0.5*dim1*dim2));
    }
}
class Square extends Figure{
    Square(int s){
        super(s,s);
    }
    @Override
    void Area(){
        System.out.println("Area = "+(dim1*dim2));
    }
}
public class fin15 {
    public static void main(String[] args){
        Figure[] figures = {new Rectangle(2, 3),
            new Triangle(2, 7),
            new Square(5)
        };
        for(Figure f: figures){
            f.Area();
        }
    }
}
