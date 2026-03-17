import java.util.Scanner;

public class boolPal {
    boolean Palindrome(int n){
        int temp = n;
        int r = 0, d;
        while(n!=0){
            d = n%10;
            r = r*10 +d;
            n = n/10;
        }
        if(temp == r)
            return true;
        else
            return false;
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter num to check palindrome: ");
        int num = sc.nextInt();
        boolPal p = new boolPal();
 
        boolean result = p.Palindrome(num);
        System.out.println("Palindrome: "+result);
        sc.close();
    }
}
