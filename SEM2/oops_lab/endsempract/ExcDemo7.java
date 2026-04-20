// Throw Demo
public class ExcDemo7 {
    public static void main(String[] args){
        try{
            System.out.println("Before throw");
            throw new ArithmeticException();
        } catch (ArithmeticException e){
            System.out.println("Arithmetic exception caught");
        }
        System.out.println("After try/catch block");    
    }
}
