import java.util.Scanner;

public class lesson1_4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Step 1: Get number of products in stock
        System.out.print("Enter number of products in stock: ");
        int n = sc.nextInt();
        sc.nextLine(); // Consume newline
        
        // Step 2: Create separate arrays for product info
        String[] productNames = new String[n];
        double[] productPrices = new double[n];
        int[] stockQuantity = new int[n];
        
        // Step 3: Input product information
        System.out.println("\n--- Enter Product Information ---");
        for (int i = 0; i < n; i++) {
            System.out.print("Product " + (i + 1) + " name: ");
            productNames[i] = sc.nextLine();
            
            System.out.print("Product " + (i + 1) + " price: Rs");
            productPrices[i] = sc.nextDouble();
            
            System.out.print("Product " + (i + 1) + " stock quantity: ");
            stockQuantity[i] = sc.nextInt();
            sc.nextLine(); // Consume newline
            System.out.println();
        }
        
        // Step 4: Display available products
        System.out.println("\n--- Available Products ---");
        displayProducts(productNames, productPrices, stockQuantity);
        
        // Step 5: Purchase process
        System.out.print("\nHow many different products do you want to purchase? ");
        int purchaseCount = sc.nextInt();
        
        double totalBill = 0;
        System.out.println("\n--- Enter Purchase Details ---");
        
        for (int i = 0; i < purchaseCount; i++) {
            System.out.print("Enter product number to purchase (1-" + n + "): ");
            int productIndex = sc.nextInt() - 1; // Convert to 0-based index
            
            // Validate product number
            if (productIndex < 0 || productIndex >= n) {
                System.out.println("Invalid product number!");
                i--; // Retry this iteration
                continue;
            }
            
            System.out.print("Enter quantity for " + productNames[productIndex] + ": ");
            int quantity = sc.nextInt();
            
            // Check if enough stock is available
            if (quantity > stockQuantity[productIndex]) {
                System.out.println("Only " + stockQuantity[productIndex] + " items available!");
                i--; // Retry this iteration
                continue;
            }
            
            // Calculate item total and add to bill
            double itemTotal = productPrices[productIndex] * quantity;
            totalBill += itemTotal;
            
            // Update stock
            stockQuantity[productIndex] -= quantity;
            
            System.out.println("Added: " + quantity + " x " + productNames[productIndex] + 
                             " = Rs" + String.format("%.2f", itemTotal));
            System.out.println();
        }
        
        // Step 6: Display final bill
        System.out.println("\n========== BILL ==========");
        System.out.println("Total Amount: Rs" + String.format("%.2f", totalBill));
        System.out.println("==========================");
        
        sc.close();
    }
    
    // Method to display all products
    static void displayProducts(String[] names, double[] prices, int[] quantities) {
        System.out.println("No.\tName\t\t\tPrice\t\tStock");
        System.out.println("---------------------------------------------------");
        for (int i = 0; i < names.length; i++) {
            System.out.printf("%d\t%-20s\tRs%.2f\t\t%d\n", 
                            (i + 1), names[i], prices[i], quantities[i]);
        }
    }
}
