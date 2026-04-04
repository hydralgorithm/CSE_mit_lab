package com.ecommerce.orders;

import com.ecommerce.exceptions.InvalidOrderException;

public class Order {

    protected String orderId;
    protected String customerName;
    protected double orderAmount;

    public Order(String orderId, String customerName, double orderAmount)
                 throws InvalidOrderException {
        if (orderAmount <= 0) {
            throw new InvalidOrderException(
                "Invalid order amount: " + orderAmount +
                ". Amount must be greater than zero.");
        }
        this.orderId      = orderId;
        this.customerName = customerName;
        this.orderAmount  = orderAmount;
    }

    public double calculateTotal() {
        return orderAmount;
    }

    public String toString() {
        return "Order ID: " + orderId +
               "\nCustomer: " + customerName +
               "\nOrder Amount: " + orderAmount;
    }
}
