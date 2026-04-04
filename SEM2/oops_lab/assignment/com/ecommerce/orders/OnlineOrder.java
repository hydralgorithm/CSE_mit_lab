/*
 * File    : OnlineOrder.java
 * Package : com.ecommerce.orders
 * Purpose : Subclass of Order representing an online order.
 *           Implements Discountable (10% discount) and
 *           Taxable (18% tax) interfaces.
 *           Total = (amount - 10% discount + 18% tax) + shipping
 *           Constructor chains to superclass using super keyword.
 *           calculateTotal() and toString() are overridden.
 */
package com.ecommerce.orders;

import com.ecommerce.exceptions.InvalidOrderException;

public class OnlineOrder extends Order implements Discountable, Taxable {

    private String deliveryAddress;
    private double shippingCharge;

    // Constructor chains to Order superclass using super
    public OnlineOrder(String orderId, String customerName,
                       double orderAmount, String deliveryAddress,
                       double shippingCharge) throws InvalidOrderException {
        super(orderId, customerName, orderAmount);
        this.deliveryAddress = deliveryAddress;
        this.shippingCharge  = shippingCharge;
    }

    // Applies 10% discount - satisfies Discountable interface
    public double applyDiscount(double amount) {
        return amount - (amount * 0.10);
    }

    // Applies 18% tax - satisfies Taxable interface
    public double applyTax(double amount) {
        return amount + (amount * 0.18);
    }

    // Overrides calculateTotal from Order
    // Applies discount first, then tax, then adds shipping
    public double calculateTotal() {
        double afterDiscount = applyDiscount(orderAmount);
        double afterTax      = applyTax(afterDiscount);
        return afterTax + shippingCharge;
    }

    // Overrides toString from Order to include online specific details
    public String toString() {
        return super.toString() +
               "\nDelivery Address: " + deliveryAddress +
               "\nShipping Charge : " + shippingCharge +
               "\nTotal (10% discount + 18% tax + shipping): "
               + calculateTotal();
    }
}