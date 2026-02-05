import java.util.Scanner;

public class lesson1_2{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.printf("Enter num1: ");
        int num1 = sc.nextInt();
        System.out.printf("\nEnter num2: ");
        int num2 = sc.nextInt();

        while (num2 != 0) {
            int sum = num1 ^ num2;
            int carr = (num1 & num2) << 1;
            num1 = sum;
            num2 = carr;
        }

        System.out.println("Sum is "+num1);
        if ((num1 & 1) == 0){
            System.out.println(num1 + " is even!");
        } else {
            System.out.println(num1 + " is odd!");
        }
        
    }
}

