import java.util.Scanner;

public class palindrome {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number: ");
        int n = sc.nextInt();
        int temp = n, rev = 0, d;
        
        while(n!=0){
            d = n%10;
            rev = rev * 10 + d;
            n = n/10;
        }

        if(temp == rev){
            System.out.println("Palindrome!");
        } else {
            System.out.println("Not Palindrome!");
        }

        sc.close();
    }
}
