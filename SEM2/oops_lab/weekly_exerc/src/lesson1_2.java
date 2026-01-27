import java.util.Scanner;

public class lesson1_2 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter first number: ");
        int a = input.nextInt();
        System.out.print("Enter second number: ");
        int b = input.nextInt();

        while (b != 0) {
            int carry = a & b; // Find bits that both have 1s (the carries)
            a = a ^ b;         // Add bits where at least one is 0 (sum without carry)
            b = carry << 1;    // Shift carry to the left to add it in the next loop
        }

        int sum = a; // 'a' now holds the final sum
        System.out.println("The sum is: " + sum);
        
        if ((sum & 1) == 0) {
            System.out.println(sum + " is an EVEN number.");
        } else {
            System.out.println(sum + " is an ODD number.");
        }

        input.close();
    }
}



