import java.util.Scanner;

public class lesson1_1 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter hours worked: ");
        double hours = input.nextDouble();
        System.out.println("Enter hourly rate: ");
        double rate = input.nextDouble();

        double totalPay = 0;

        if(hours<=40){
            totalPay = rate * hours;
        } else {
            double regularPay = 40 * rate;
            double extraHours = hours - 40;
            double overTimePay = extraHours * rate * 1.5;
            
            totalPay = regularPay + overTimePay;
        }

        System.out.printf("Your total salary is: Rs%.2f",totalPay);

        input.close();
    }
}
