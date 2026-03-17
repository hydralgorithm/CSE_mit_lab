import java.util.Scanner;

public class retailStore {
    public static void main(String args[]){
        int[] productPrices = {100,450,250,200,500};
        int totalprice = 0;

        for(int p : productPrices){
            totalprice += p;
        }

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter discount and tax percentages: ");
        double discountPerc = sc.nextDouble();
        double taxPerc = sc.nextDouble();
        sc.close();

        double widenTotalprice = totalprice;
        int disc = (int)discountPerc;
        int tax = (int)taxPerc;

        widenTotalprice = widenTotalprice - (widenTotalprice*disc)/100;
        widenTotalprice = widenTotalprice + (widenTotalprice*tax)/100;

        System.out.println("Before total: "+totalprice);
        System.out.println("After charges: "+widenTotalprice);
        
    }
}
