import java.util.Scanner;

public class numGCD {
    public static int findGCD(int a, int b){
        while(b!=0) {
            int temp = b;
            b = a%b;
            a= temp;
        }
        return a;
    }
    public static void main(String[] args){
        System.out.println("Enter a and b:");
        Scanner sc = new Scanner(System.in);
        int a,b;
        a = sc.nextInt();
        b= sc.nextInt();
        int gcd = findGCD(a, b);
        System.out.println(gcd);
        sc.close();
    }
}
