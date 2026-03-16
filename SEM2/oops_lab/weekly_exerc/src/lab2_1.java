import java.util.Scanner;

public class lab2_1 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter total distance travelled(in km): ");
        int x = sc.nextInt();
        sc.close();
        int totalCost;
        if(x<=5){
            totalCost = x * 10;
        } else if(x<=20){
            totalCost = (5 * 10) + ((x-5)*8);
        } else if(x<=45){
            totalCost = (5 * 10) + (15 * 8) + ((x-20)*5);
        } else {
            System.out.println("Out of calc limits!");
            return;
        }
        System.out.println("Total Cost = Rs" +totalCost);
    }
}
