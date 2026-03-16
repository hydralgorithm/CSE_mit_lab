import java.util.Scanner;

public class lab2_2 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter 9-digit registration number: ");
        String n = sc.nextLine();
        if (n.length() < 9) {
            System.out.println("Invalid registration number.");
            return;
        }
        String y = n.substring(0, 2);
        int year = 2000 + Integer.parseInt(y);
        System.out.println("Year of joining: " + year);
        sc.close();
    }
}
