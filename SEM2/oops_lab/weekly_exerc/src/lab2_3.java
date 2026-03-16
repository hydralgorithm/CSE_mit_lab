import java.util.Scanner;

public class lab2_3 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter date of birth(DD-MM-YYYY): ");
        String dob = sc.nextLine();
        if (dob.length() < 10) {
            System.out.println("Invalid date format.");
            return;
        }
        int birthYear = Integer.parseInt(dob.substring(6,10));
        System.out.print("Enter years of service: ");
        int serve = sc.nextInt();
        if (serve < 0 || serve > 60) {
            System.out.println("Years of service must be between 0 and 60.");
            return;
        }

        int retireYear = birthYear + 60;
        System.out.println("You retire at "+(dob.substring(0,6))+retireYear);
        sc.close();
    }
}
