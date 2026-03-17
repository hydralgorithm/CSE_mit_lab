import java.util.Scanner;

public class naturalSum {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of natural numbers to find sum of: ");
        int n = sc.nextInt();
        int sum = 0;
        for(int i=1; i<=n; i++){
            sum += i;
        }
        System.out.println("Sum: "+sum);
        sc.close();
    }    
}
