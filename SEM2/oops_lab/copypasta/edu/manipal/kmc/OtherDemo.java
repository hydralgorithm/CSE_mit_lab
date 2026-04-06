package edu.manipal.kmc;

import edu.manipal.mit.Student; // Error: Student is not public

public class OtherDemo {
    public static void main(String[] args) {
        Student s = new Student(); // Compilation Error
        s.display();               // Compilation Error
    }
}