package com.ecommerce.orders;

import com.ecommerce.exceptions.InvalidOrderException;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("=== E-Commerce Order Processing System ===");

        try {

            System.out.println("\n--- Enter Online Order Details ---");
            System.out.print("Enter Order ID: ");
            String onlineId = sc.next();

            System.out.print("Enter Customer Name: ");
            String onlineName = sc.next();

            System.out.print("Enter Order Amount: ");
            double onlineAmount = sc.nextDouble();

            System.out.print("Enter Delivery Address: ");
            String address = sc.next();

            System.out.print("Enter Shipping Charge: ");
            double shipping = sc.nextDouble();

            System.out.println("\n--- Enter In-Store Order Details ---");
            System.out.print("Enter Order ID: ");
            String storeId = sc.next();

            System.out.print("Enter Customer Name: ");
            String storeName2 = sc.next();

            System.out.print("Enter Order Amount: ");
            double storeAmount = sc.nextDouble();

            System.out.print("Enter Store Name: ");
            String storeName = sc.next();

            Order order1 = new OnlineOrder(onlineId, onlineName,
                                           onlineAmount, address, shipping);

            Order order2 = new InStoreOrder(storeId, storeName2,
                                            storeAmount, storeName);

            System.out.println("\n=== Order Details ===");
            System.out.println("\n" + order1.toString());
            System.out.println("\n" + order2.toString());

        } catch (InvalidOrderException e) {
            System.out.println("Order Error: " + e.getMessage());

        } catch (Exception e) {
            System.out.println("Unexpected Error: " + e.getMessage());

        } finally {
            System.out.println("\nSystem: Order processing complete. Resources cleaned up.");
            sc.close();
        }
    }
}
