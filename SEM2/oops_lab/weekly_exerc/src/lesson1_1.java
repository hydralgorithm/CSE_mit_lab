import java.util.Scanner;

public class lesson1_1 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.printf("Enter hours worked: ");
        double hours = sc.nextDouble();
        System.out.printf("\nEnter hourly rate: ");
        double rate = sc.nextDouble();

        double totalPay = 0;
        if (hours<=40){
            totalPay = hours * rate;
        } else if (hours>40) {
            totalPay = (40*rate) + (1.5 * rate * (hours - 40));
        }

        System.out.printf("\nYour total salary is: Rs%.2f",totalPay);
        sc.close();
    }
}