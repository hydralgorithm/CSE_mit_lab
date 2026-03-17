class Complex{
    double real, imag;
    Complex(double r, double i){
        real = r;
        imag = i;
    }
    void display(){
        System.out.println(real+" + "+imag+"i");
    }
    Complex addComplex(Complex c){
        double newReal = real+ c.real;
        double newImag = imag + c.imag;
        return new Complex(newReal, newImag);
    }
}

public class cmplxDemo {
    public static void main(String args[]){
        Complex c1 = new Complex(3,4);
        Complex c2 = new Complex(6,7);
        c1.display();
        c2.display();
        
        Complex result = c1.addComplex(c2);
        result.display();
    }
}
