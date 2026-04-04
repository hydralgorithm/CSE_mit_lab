/*
 * File    : InStoreOrder.java
 * Package : com.ecommerce.orders
 * Purpose : Subclass of Order representing an in-store order.
 *           Implements Discountable (5% discount) and
 *           Taxable (12% tax) interfaces.
 *           Total = (amount - 5% discount + 12% tax)
 *           No shipping charge for in-store orders.
 *           Constructor chains to superclass using super keyword.
 *           calculateTotal() and toString() are overridden.
 */
package com.ecommerce.orders;

import com.ecommerce.exceptions.InvalidOrderException;

public class InStoreOrder extends Order implements Discountable, Taxable {

    private String storeName;

    // Constructor chains to Order superclass using super
    public InStoreOrder(String orderId, String customerName,
                        double orderAmount, String storeName)
                        throws InvalidOrderException {
        super(orderId, customerName, orderAmount);
        this.storeName = storeName;
    }

    // Applies 5% discount - satisfies Discountable interface
    public double applyDiscount(double amount) {
        return amount - (amount * 0.05);
    }

    // Applies 12% tax - satisfies Taxable interface
    public double applyTax(double amount) {
        return amount + (amount * 0.12);
    }

    // Overrides calculateTotal from Order
    // Applies discount first then tax, no shipping for in-store
    public double calculateTotal() {
        double afterDiscount = applyDiscount(orderAmount);
        double afterTax      = applyTax(afterDiscount);
        return afterTax;
    }

    // Overrides toString from Order to include in-store specific details
    public String toString() {
        return super.toString() +
               "\nStore Name : " + storeName +
               "\nTotal (5% discount + 12% tax): "
               + calculateTotal();
    }
}