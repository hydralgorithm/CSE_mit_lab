package com.ecommerce.orders;

import com.ecommerce.exceptions.InvalidOrderException;

public class OnlineOrder extends Order implements Discountable, Taxable {
    private final double shippingFee;
    private final double discountRate;
    private final double taxRate;

    public OnlineOrder(String orderId, String customerName, double baseAmount,
                       double shippingFee, double discountRate, double taxRate) throws InvalidOrderException {
        super(orderId, customerName, baseAmount);
        this.shippingFee = shippingFee;
        this.discountRate = discountRate;
        this.taxRate = taxRate;
    }

    @Override
    public double applyDiscount(double amount) {
        return amount - (amount * discountRate);
    }

    @Override
    public double applyTax(double amount) {
        return amount + (amount * taxRate);
    }

    @Override
    public double calculateTotal() {
        double amount = getBaseAmount();
        amount = applyDiscount(amount);
        amount = applyTax(amount);
        return amount + shippingFee;
    }

    @Override
    public String toString() {
        return "Online " + super.toString() + ", Shipping Fee: " + shippingFee;
    }
}
