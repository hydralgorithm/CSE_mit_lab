import java.util.Scanner;

public class lab2_5 {
    public static int factorial(int n){
        if(n==0 || n==1){
            return 1;
        } else {
            return n * factorial(n-1);
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter num to find factorial of: ");
        int num = sc.nextInt();
        sc.close();
        System.out.println("Factorial of "+num+" is "+factorial(num));
    }
}
