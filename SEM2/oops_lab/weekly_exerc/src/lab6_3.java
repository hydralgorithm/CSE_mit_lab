import java.util.Scanner;

class Student {
    String name;

    Student(String name) {
        this.name = name;
    }

    String extractInitials() {
        String in = "";
        boolean take = true;
        for (int i = 0; i < name.length(); i++) {
            char ch = name.charAt(i);
            if (ch == ' ') take = true;
            else if (take) {
                in += Character.toUpperCase(ch);
                take = false;
            }
        }
        return in;
    }

    String removeWhitespace() {
        String out = "";
        for (int i = 0; i < name.length(); i++) {
            if (name.charAt(i) != ' ') out += name.charAt(i);
        }
        return out;
    }
}

public class lab6_3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of students: ");
        int n = sc.nextInt();
        sc.nextLine();

        Student[] s = new Student[n];
        for (int i = 0; i < n; i++) {
            System.out.print("Enter name: ");
            s[i] = new Student(sc.nextLine());
        }

        System.out.print("Enter substring to search: ");
        String sub = sc.nextLine().toLowerCase();

        for (int i = 0; i < n; i++) {
            System.out.println("\nName: " + s[i].name);
            System.out.println("Initials: " + s[i].extractInitials());
            System.out.println("No space: " + s[i].removeWhitespace());
        }

        System.out.println("\nNames containing \"" + sub + "\":");
        for (int i = 0; i < n; i++) {
            if (s[i].name.toLowerCase().contains(sub)) System.out.println(s[i].name);
        }

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (s[i].name.compareToIgnoreCase(s[j].name) > 0) {
                    Student t = s[i]; s[i] = s[j]; s[j] = t;
                }
            }
        }

        System.out.println("\nSorted names:");
        for (int i = 0; i < n; i++) System.out.println(s[i].name);

        sc.close();
    }
}
