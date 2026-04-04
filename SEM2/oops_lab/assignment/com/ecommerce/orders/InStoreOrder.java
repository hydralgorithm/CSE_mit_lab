package com.ecommerce.orders;

import com.ecommerce.exceptions.InvalidOrderException;

public class InStoreOrder extends Order implements Discountable, Taxable {

    private String storeName;

    public InStoreOrder(String orderId, String customerName,
                        double orderAmount, String storeName)
                        throws InvalidOrderException {
        super(orderId, customerName, orderAmount);
        this.storeName = storeName;
    }

    public double applyDiscount(double amount) {
        return amount - (amount * 0.05);
    }

    public double applyTax(double amount) {
        return amount + (amount * 0.12);
    }

    public double calculateTotal() {
        double afterDiscount = applyDiscount(orderAmount);
        double afterTax      = applyTax(afterDiscount);
        return afterTax;
    }

    public String toString() {
        return super.toString() +
               "\nStore Name: " + storeName +
               "\nTotal (after 5% discount + 12% tax): "
               + calculateTotal();
    }
}
