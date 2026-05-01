package SEM2.oops_lab.endsemfin;
import java.util.Scanner;

public class fin8 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int sum=0;
        System.out.print("Enter lim1: ");
        int lim1 = sc.nextInt();
        System.out.print("Enter lim2: ");
        int lim2 = sc.nextInt();
        for(int i=lim1; i<=lim2; i++){
            if(checkArmstrong(i)){
                System.out.print(i+" ");
                sum+=i;
            } 
        }   
        System.out.println();
        System.out.println("Sum: "+sum);
        sc.close();
    }
    public static boolean checkArmstrong(int n){
        int dnum=0, arm=0;
        int temp = n;
        while(temp!=0){
            dnum++;
            temp/=10;
        }
        temp = n;
        while (temp!=0) {
            int d = temp%10;
            arm = arm + (int)Math.pow(d,dnum);
            temp /= 10;
        }
        if(n==arm){
            return true;
        } else{
            return false;
        }
    }
}
