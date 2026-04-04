/*
 * File    : Order.java
 * Package : com.ecommerce.orders
 * Purpose : Superclass for all order types.
 *           Stores common fields - orderId, customerName, orderAmount.
 *           Throws InvalidOrderException if amount is invalid.
 *           calculateTotal() is meant to be overridden by subclasses.
 *           toString() is overridden to display order details.
 */
package com.ecommerce.orders;

import com.ecommerce.exceptions.InvalidOrderException;

public class Order {

    // Common fields shared by all order types
    protected String orderId;
    protected String customerName;
    protected double orderAmount;

    // Constructor validates order amount before initializing fields
    public Order(String orderId, String customerName, double orderAmount)
                 throws InvalidOrderException {

        // Throw checked exception if order amount is zero or negative
        if (orderAmount <= 0) {
            throw new InvalidOrderException(
                "Invalid order amount: " + orderAmount +
                ". Amount must be greater than zero.");
        }

        this.orderId      = orderId;
        this.customerName = customerName;
        this.orderAmount  = orderAmount;
    }

    // Base implementation - overridden by subclasses
    public double calculateTotal() {
        return orderAmount;
    }

    // Overrides default toString to display order details
    public String toString() {
        return "Order ID    : " + orderId +
               "\nCustomer    : " + customerName +
               "\nOrder Amount: " + orderAmount;
    }
}