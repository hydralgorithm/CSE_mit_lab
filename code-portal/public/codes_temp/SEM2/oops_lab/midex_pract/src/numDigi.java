import java.util.Scanner;

public class numDigi {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number to count digits: ");
        int n = Math.abs(sc.nextInt());
        int count = 0;
        while(n!=0){
            count +=1;
            n = n/10;
        }
        System.out.println("Num of digits = "+count);
        sc.close();
    }
}
