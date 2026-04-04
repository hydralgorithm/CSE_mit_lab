package com.ecommerce.orders;

import com.ecommerce.exceptions.InvalidOrderException;

public class Order {
    private final String orderId;
    private final String customerName;
    private final double baseAmount;

    public Order(String orderId, String customerName, double baseAmount) throws InvalidOrderException {
        // Validate base amount in the superclass constructor.
        if (baseAmount <= 0) {
            throw new InvalidOrderException("Order amount must be positive.");
        }
        this.orderId = orderId;
        this.customerName = customerName;
        this.baseAmount = baseAmount;
    }

    public double calculateTotal() {
        // Base implementation, overridden by subclasses.
        return baseAmount;
    }

    public double getBaseAmount() {
        return baseAmount;
    }

    public String getOrderId() {
        return orderId;
    }

    public String getCustomerName() {
        return customerName;
    }

    @Override
    public String toString() {
        return "Order ID: " + orderId + ", Customer: " + customerName + ", Base Amount: " + baseAmount;
    }
}
