/*
 * File    : Taxable.java
 * Package : com.ecommerce.orders
 * Purpose : Interface that enforces a contract for
 *           applying tax to an order amount.
 *           Any class implementing this must provide
 *           its own applyTax() logic.
 */
package com.ecommerce.orders;

public interface Taxable {
    double applyTax(double amount);
}