import java.util.Scanner;

public class lab1_4 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of different products in stock: ");
        int prodNum = sc.nextInt();
        if (prodNum <= 0) {
            System.out.println("Product count must be positive.");
            return;
        }
        
        String[] productNames = new String[prodNum];
        double[] productPrices = new double[prodNum];
        int[] productQuant = new int[prodNum];

        System.out.println("------------------------------");
        System.out.println("      Input Product Info      ");
        System.out.println("------------------------------");
        sc.nextLine();
        for(int i=0; i<prodNum; i++){
            System.out.println("Prod "+(i+1)+" info:");
            System.out.print("Enter product name: ");
            productNames[i] = sc.nextLine();
            System.out.print("Enter product price: ");
            productPrices[i] = sc.nextDouble();
            System.out.print("Enter product quantity: ");
            productQuant[i] = sc.nextInt();
            sc.nextLine();
        }
        System.out.println("-----Displaying Available products-----");
        displayProducts(productNames,productPrices, productQuant);

        System.out.print("Choose no. of different products you want to buy: ");
        int buyCount = sc.nextInt();
        if (buyCount <= 0) {
            System.out.println("Nothing to buy.");
            return;
        }

        double totalBill = 0.0;
        System.out.println("-----Purchase-----");
        for (int i = 0; i < buyCount; i++) {
            System.out.print("Enter product number (1 to " + prodNum + "): ");
            int prodIndex = sc.nextInt() - 1;
            if (prodIndex < 0 || prodIndex >= prodNum) {
                System.out.println("Invalid product number. Try again.");
                i--;
                continue;
            }
            System.out.print("Enter quantity: ");
            int qty = sc.nextInt();
            if (qty <= 0) {
                System.out.println("Quantity must be positive. Try again.");
                i--;
                continue;
            }
            if (qty > productQuant[prodIndex]) {
                System.out.println("Not enough stock. Available: " + productQuant[prodIndex]);
                i--;
                continue;
            }

            double cost = qty * productPrices[prodIndex];
            productQuant[prodIndex] -= qty;
            totalBill += cost;
            System.out.printf("%s x %d = %.2f\n", productNames[prodIndex], qty, cost);
        }

        System.out.printf("Total bill: %.2f\n", totalBill);
        System.out.println("-----Updated Stock-----");
        displayProducts(productNames,productPrices, productQuant);
        sc.close();
    }

    static void displayProducts(String[] n, double[] p, int[] q){
        System.out.printf("No.\tName\t\tPrice\tQty\n");
        System.out.println("--------------------------------------");
        for(int i=0; i<n.length; i++){
            System.out.printf("%d\t%s\t\t%.2f\t%d\n",(i+1),n[i],p[i],q[i]);
        }
    }
}
