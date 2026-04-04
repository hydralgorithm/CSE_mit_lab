package com.ecommerce.orders;

import com.ecommerce.exceptions.InvalidOrderException;

import java.util.InputMismatchException;
import java.util.Scanner;

public class OrderDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        try {
            // Input order type and shared fields.
            String type = sc.next();
            String orderId = sc.next();
            String customer = sc.next();
            double baseAmount = sc.nextDouble();
            double discountRate = sc.nextDouble();
            double taxRate = sc.nextDouble();

            Order order;

            if ("ONLINE".equalsIgnoreCase(type)) {
                double shippingFee = sc.nextDouble();
                order = new OnlineOrder(orderId, customer, baseAmount, shippingFee, discountRate, taxRate);
            } else if ("INSTORE".equalsIgnoreCase(type)) {
                String storeCode = sc.next();
                order = new InStoreOrder(orderId, customer, baseAmount, storeCode, discountRate, taxRate);
            } else {
                throw new InvalidOrderException("Unknown order type.");
            }

            // Runtime polymorphism via Order reference.
            System.out.println(order);
            System.out.println("Total: " + order.calculateTotal());

        } catch (InputMismatchException ex) {
            System.out.println("Input error: invalid data type.");
        } catch (InvalidOrderException ex) {
            System.out.println("Order error: " + ex.getMessage());
        } finally {
            // Cleanup resource.
            sc.close();
        }
    }
}
