import java.util.Scanner;

public class lab1_2 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter num1: ");
        int a = sc.nextInt();
        System.out.print("Enter num2: ");
        int b = sc.nextInt();
        sc.close();
        int sum = addBitwise(a, b);

        System.out.println("Sum = "+sum);

        if((sum & 1) == 0){
            System.out.println("Sum is even");
        } else {
            System.out.println("Sum is odd");
        }
        
    }
    static int addBitwise(int a, int b){
        while(b!=0){
            int sum = a^b;
            int carry = (a&b) << 1;
            a = sum;
            b = carry;
        }
        return a;
    }
}
