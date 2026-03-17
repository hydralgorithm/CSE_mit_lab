import java.util.Arrays;
import java.util.Scanner;

public class lab6_1 {

    static String reverseString(String str) {
        StringBuilder sb = new StringBuilder(str);
        return sb.reverse().toString();
    }

    static String sortAlphabetically(String str) {
        char[] arr = str.toCharArray();
        Arrays.sort(arr);
        return new String(arr);
    }

    static boolean isPalindrome(String str) {
        String rev = reverseString(str);
        return str.equalsIgnoreCase(rev);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String str = sc.nextLine();

        int choice;
        do {
            System.out.println("\n1. Palindrome Check");
            System.out.println("2. Sort Alphabetically");
            System.out.println("3. Reverse String");
            System.out.println("4. Concatenate (original + reversed)");
            System.out.println("5. Quit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    if (isPalindrome(str)) {
                        System.out.println("The string is a palindrome.");
                    } else {
                        System.out.println("The string is not a palindrome.");
                    }
                    break;
                case 2:
                    System.out.println("Alphabetical order string: " + sortAlphabetically(str));
                    break;
                case 3:
                    System.out.println("Reversed string: " + reverseString(str));
                    break;
                case 4:
                    String rev = reverseString(str);
                    System.out.println("Concatenated string: " + str + rev);
                    break;
                case 5:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice. Enter 1 to 5.");
            }
        } while (choice != 5);

        sc.close();
    }
}
