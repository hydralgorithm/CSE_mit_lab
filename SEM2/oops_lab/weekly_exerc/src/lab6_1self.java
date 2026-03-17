import java.util.Arrays;
import java.util.Scanner;
public class lab6_1self {
    static String reverse(String str){
        StringBuilder sb = new StringBuilder(str);
        String rev = sb.reverse().toString();
        return rev;
    }
    static boolean isPalindrome(String str){
        String rev = reverse(str);
        return str.equalsIgnoreCase(rev);
    }
    static String sortAlphabetically(String str){
        char[] arr = str.toCharArray();
        Arrays.sort(arr);
        return new String(arr);
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the string: ");
        String str = sc.nextLine();
        int choice;
        do{
            System.out.println("\n1. Check Palindrome");
            System.out.println("2. Sort Alphabetically");
            System.out.println("3. Reverse String");
            System.out.println("4. Concatanate");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();
            switch(choice){
                case 1: if(isPalindrome(str)){
                            System.out.println("It is palindrome!");
                        } else {
                            System.out.println("It is not Palindrome!");
                        }
                        break;
                case 2: System.out.println("Sorted String: "+sortAlphabetically(str));
                        break;
                case 3: System.out.println("Reversed String: "+reverse(str));
                        break;
                case 4: String rev = reverse(str);
                        System.out.println("Concatanated String : "+str+rev);
                        break;
                case 5: System.out.println("Exiting...");
                        break;
                default: System.out.println("Invalid choice!");
            }
        }while(choice != 5);
        sc.close();
    }
}
