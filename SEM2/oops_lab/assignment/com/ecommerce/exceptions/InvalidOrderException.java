/*
 * Program  : E-Commerce Order Processing System
 * File     : InvalidOrderException.java
 * Package  : com.ecommerce.exceptions
 * Purpose  : Custom checked exception thrown when an order
 *            amount is invalid (zero or negative).
 *            Being checked, it must be declared in the
 *            throws clause of any method that throws it.
 */
package com.ecommerce.exceptions;

public class InvalidOrderException extends Exception {

    // Constructor accepts a message describing the error
    public InvalidOrderException(String message) {
        super(message);
    }
}