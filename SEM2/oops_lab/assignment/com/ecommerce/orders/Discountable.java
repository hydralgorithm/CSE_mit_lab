/*
 * File    : Discountable.java
 * Package : com.ecommerce.orders
 * Purpose : Interface that enforces a contract for
 *           applying discount to an order amount.
 *           Any class implementing this must provide
 *           its own applyDiscount() logic.
 */
package com.ecommerce.orders;

public interface Discountable {
    double applyDiscount(double amount);
}