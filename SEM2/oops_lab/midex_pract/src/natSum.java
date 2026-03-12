import java.util.Scanner;
public class natSum {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter firt x N numbers to find sum of: ");
        int x = sc.nextInt();
        if(x<1){
            System.out.println("Invalid Input!");
            return;
        }
        int sum = 0;
        for(int i=1; i<=x;i++){
            sum += i;
        }
        System.out.println("Sum = "+ sum);
        sc.close();
    }
}
