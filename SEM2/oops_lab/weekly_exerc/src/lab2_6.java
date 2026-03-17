import java.util.Scanner;

public class lab2_6 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int totalConsumption = 0;
        System.out.println("Enter consumption for 7 days - ");
        for(int i=0; i<7; i++){
            System.out.print("Consumption for day "+(i+1)+" : ");
            int dailyUnits = sc.nextInt();
            totalConsumption += dailyUnits;
        }
        int choice;
        int totalBill = 0;
        if(totalConsumption <= 100){
            choice = 1;
        } else if(totalConsumption <= 200){
            choice = 2;
        } else{
            choice = 3;
        }
        switch(choice){
            case 1: totalBill = totalConsumption * 7;
                    break;
            case 2: totalBill = (100*7) + ((totalConsumption-100) * 8);
                    break;
            case 3: totalBill = (100*7) + (100 * 8) + ((totalConsumption-200)*10);
                    break;
            default: System.out.println("Invalid Scenario");
                    break;
        }
        System.out.println("Total electricity bill = Rs"+totalBill);
        sc.close();
    }
}
