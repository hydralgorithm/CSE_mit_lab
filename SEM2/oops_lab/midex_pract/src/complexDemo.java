class Complex{
    double real, imag;
    Complex(double r, double i){
        real = r;
        imag = i;
    }
    void Display(){
        System.out.println(real+" + "+imag+"i");
    }
}

public class complexDemo {
    public static void main(String[] args) {
        Complex c = new Complex(4, 5);
        c.Display();
    }
}
