import java.util.Scanner;

class Employee {
    String name;

    Employee(String n) {
        name = n;
    }

    String formatEmployeeName() {
        String[] words = name.toLowerCase().split(" ");
        String result = "";

        for (int i = 0; i < words.length; i++) {
            if (words[i].length() > 0) {
                result += Character.toUpperCase(words[i].charAt(0)) + words[i].substring(1);
                if (i < words.length - 1) result += " ";
            }
        }
        return result;
    }

    String generateEmail() {
        String formatted = formatEmployeeName().toLowerCase();
        String[] parts = formatted.split(" ");

        if (parts.length == 1) {
            return parts[0] + "@example.com";
        } else {
            return parts[0].charAt(0) + parts[1] + "@example.com"; // jdoe@example.com
        }
    }
}

public class lab6_2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of employees: ");
        int n = sc.nextInt();
        sc.nextLine();

        Employee[] emp = new Employee[n];

        for (int i = 0; i < n; i++) {
            System.out.print("Enter employee name: ");
            String name = sc.nextLine();
            emp[i] = new Employee(name); // parameterized constructor
        }

        System.out.println("\n--- Output ---");
        for (int i = 0; i < n; i++) {
            System.out.println("Formatted Name: " + emp[i].formatEmployeeName());
            System.out.println("Email: " + emp[i].generateEmail());
            System.out.println();
        }

        sc.close();
    }
}
