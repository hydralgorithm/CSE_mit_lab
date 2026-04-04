/*
 * File    : Main.java
 * Package : com.ecommerce.orders
 * Purpose : Entry point of the E-Commerce Order Processing System.
 *           Demonstrates the following concepts:
 *           - Runtime polymorphism using Order reference
 *           - Constructor chaining via super keyword
 *           - Method overriding for calculateTotal() and toString()
 *           - Multiple catch blocks for exception handling
 *           - Finally block for resource cleanup
 */
package com.ecommerce.orders;

import com.ecommerce.exceptions.InvalidOrderException;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("=== E-Commerce Order Processing System ===");

        try {

            // --- Reading Online Order details from user ---
            System.out.println("\n--- Enter Online Order Details ---");
            System.out.print("Enter Order ID       : ");
            String onlineId = sc.next();

            System.out.print("Enter Customer Name  : ");
            String onlineName = sc.next();

            System.out.print("Enter Order Amount   : ");
            double onlineAmount = sc.nextDouble();

            System.out.print("Enter Delivery Address: ");
            String address = sc.next();

            System.out.print("Enter Shipping Charge: ");
            double shipping = sc.nextDouble();

            // --- Reading InStore Order details from user ---
            System.out.println("\n--- Enter In-Store Order Details ---");
            System.out.print("Enter Order ID       : ");
            String storeId = sc.next();

            System.out.print("Enter Customer Name  : ");
            String storeName2 = sc.next();

            System.out.print("Enter Order Amount   : ");
            double storeAmount = sc.nextDouble();

            System.out.print("Enter Store Name     : ");
            String storeName = sc.next();

            // Runtime polymorphism - Order reference holds subclass objects
            // Demonstrates dynamic dispatch of overridden methods
            Order order1 = new OnlineOrder(onlineId, onlineName,
                                           onlineAmount, address, shipping);

            Order order2 = new InStoreOrder(storeId, storeName2,
                                            storeAmount, storeName);

            // toString() called here is the overridden version in each subclass
            System.out.println("\n=== Order Details ===");
            System.out.println("\n" + order1.toString());
            System.out.println("\n" + order2.toString());

        } catch (InvalidOrderException e) {
            // Catches invalid order amount exception
            System.out.println("Order Error: " + e.getMessage());

        } catch (Exception e) {
            // Catches any other unexpected exceptions
            System.out.println("Unexpected Error: " + e.getMessage());

        } finally {
            // Always executes regardless of exception
            // Used for resource cleanup
            System.out.println("\nSystem: Order processing complete. Resources cleaned up.");
            sc.close();
        }
    }
}