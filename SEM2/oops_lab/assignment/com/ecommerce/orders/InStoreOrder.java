package com.ecommerce.orders;

import com.ecommerce.exceptions.InvalidOrderException;

public class InStoreOrder extends Order implements Discountable, Taxable {
    private final String storeCode;
    private final double discountRate;
    private final double taxRate;

    public InStoreOrder(String orderId, String customerName, double baseAmount,
                        String storeCode, double discountRate, double taxRate) throws InvalidOrderException {
        // Constructor chaining to validate and initialize common fields.
        super(orderId, customerName, baseAmount);
        this.storeCode = storeCode;
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
        // In-store total applies discount then tax.
        double amount = getBaseAmount();
        amount = applyDiscount(amount);
        return applyTax(amount);
    }

    @Override
    public String toString() {
        return "In-Store " + super.toString() + ", Store: " + storeCode;
    }
}
