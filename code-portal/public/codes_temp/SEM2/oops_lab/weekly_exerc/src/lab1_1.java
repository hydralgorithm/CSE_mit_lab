import java.util.Scanner;

public class lab1_1 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter no. of hours worked: ");
        double hours = sc.nextDouble();
        System.out.print("Enter hourly rate: ");
        double rate = sc.nextDouble();
        sc.close();
        double salary;
        if(hours <= 40){
            salary = hours * rate;
        } else {
            salary = (40*rate) + 1.5*rate*(hours-40);
        }
        System.out.println("Employee salary = $"+salary);
    }
}
