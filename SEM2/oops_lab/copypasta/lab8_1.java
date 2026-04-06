abstract class Figure {
    int x, y;

    Figure(int x, int y) {
        this.x = x;
        this.y = y;
    }

    abstract double area();
}

class Rectangle extends Figure {
    Rectangle(int x, int y) { super(x, y); }

    @Override
    double area() { return x * y; }
}

class Triangle extends Figure {
    Triangle(int x, int y) { super(x, y); }

    @Override
    double area() { return 0.5 * x * y; }
}

class Square extends Figure {
    Square(int x) { super(x, x); }

    @Override
    double area() { return x * x; }
}

public class lab8_1 {
    public static void main(String[] args) {
        // Dynamic Polymorphism
        Figure[] fig = {new Rectangle(5, 3), 
                        new Triangle(4, 6), 
                        new Square(4)};

        for (Figure f : fig)
            System.out.println(f.getClass().getSimpleName() + 
            " Area: " + f.area());
    }
}