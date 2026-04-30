package SEM2.oops_lab.endsemfin;
import java.util.Scanner;

class Properties{
    boolean isPerfectSquare;
    int previousNumber;
    int nextNumber;
}

public class fin3 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter num: ");
        int num = sc.nextInt();
        Properties p = get_numberProperties(num);
        System.out.println("isPerfectSquare = "+p.isPerfectSquare);
        System.out.println("Next num: "+p.nextNumber);
        System.out.println("Previous num: "+p.previousNumber);
        sc.close();
    }
    static Properties get_numberProperties(int num){
        Properties p = new Properties();
        int sqrt = (int)Math.sqrt(num);
        if(sqrt*sqrt == num){
            p.isPerfectSquare = true;
        } else{
            p.isPerfectSquare = false;
        }
        p.previousNumber = num-1;
        p.nextNumber = num+1;
        return p;
    }
}
