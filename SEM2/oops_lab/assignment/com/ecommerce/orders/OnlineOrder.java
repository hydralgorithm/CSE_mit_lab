package com.ecommerce.orders;

import com.ecommerce.exceptions.InvalidOrderException;

public class OnlineOrder extends Order implements Discountable, Taxable {

    private String deliveryAddress;
    private double shippingCharge;

    public OnlineOrder(String orderId, String customerName,
                       double orderAmount, String deliveryAddress,
                       double shippingCharge) throws InvalidOrderException {
        super(orderId, customerName, orderAmount);
        this.deliveryAddress = deliveryAddress;
        this.shippingCharge  = shippingCharge;
    }

    public double applyDiscount(double amount) {
        return amount - (amount * 0.10);
    }

    public double applyTax(double amount) {
        return amount + (amount * 0.18);
    }

    public double calculateTotal() {
        double afterDiscount = applyDiscount(orderAmount);
        double afterTax      = applyTax(afterDiscount);
        return afterTax + shippingCharge;
    }

    public String toString() {
        return super.toString() +
               "\nDelivery Address: " + deliveryAddress +
               "\nShipping Charge: " + shippingCharge +
               "\nTotal (after 10% discount + 18% tax + shipping): "
               + calculateTotal();
    }
}
