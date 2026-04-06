class Employee {
    String eName;
    int eId;
    double basic;

    Employee(String name, int id, double basic) {
        this.eName = name;
        this.eId = id;
        this.basic = basic;
    }

    double calculateSalary() {
        double gross = basic + 0.52 * basic;
        return gross - 0.30 * gross;
    }

    void displayEmployeeDetails() {
        System.out.println("Name: " + eName + 
        " | ID: " + eId + " | Net: " + calculateSalary());
    }
}

class PartTimeEmp extends Employee {
    int hoursWorked;
    static final double hourlyRate = 250.0;

    PartTimeEmp(String name, int id, int hours) {
        super(name, id, 0);
        this.hoursWorked = hours;
    }

    @Override
    double calculateSalary() {
        return hoursWorked * hourlyRate;
    }

    @Override
    void displayEmployeeDetails() {
        System.out.println("Name: " + eName + 
        " | Hours: " + hoursWorked + 
        " | Rate: " + hourlyRate + 
        " | Net: " + calculateSalary());
    }
}

class FullTimeEmp extends Employee {
    double bonus, deductions;

    FullTimeEmp(String name, int id, double basic, 
                double bonus, double deductions) {
        super(name, id, basic);
        this.bonus = bonus;
        this.deductions = deductions;
    }

    @Override
    double calculateSalary() {
        double gross = basic + 0.52 * basic + bonus;
        return gross - 0.30 * gross - deductions;
    }

    @Override
    void displayEmployeeDetails() {
        System.out.println("Name: " + eName + 
        " | Bonus: " + bonus + 
        " | Deductions: " + deductions + 
        " | Net: " + calculateSalary());
    }
}

public class lab7_2 {
    public static void main(String[] args) {
        Employee e = new Employee("John", 101, 30000);
        e.displayEmployeeDetails();

        PartTimeEmp pt = new PartTimeEmp("Sara", 102, 80);
        pt.displayEmployeeDetails();

        FullTimeEmp ft = new FullTimeEmp("Mike", 103, 40000, 5000, 2000);
        ft.displayEmployeeDetails();

        // Dynamic Polymorphism
        Employee[] arr = {e, pt, ft};
        System.out.println("\n-- Dynamic Polymorphism --");
        for (Employee emp : arr) emp.displayEmployeeDetails();
    }
}
