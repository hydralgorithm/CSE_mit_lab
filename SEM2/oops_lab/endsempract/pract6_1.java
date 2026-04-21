import java.util.Scanner;
import java.util.Arrays;

public class pract6_1 {
    public static boolean checkPalindrome(String str){
        String rev = reverse(str);
        return rev.equalsIgnoreCase(str);
    }
    public static String reverse(String str){
        StringBuilder sb = new StringBuilder(str);
        String rev = sb.reverse().toString();
        return rev;
    }
    public static String sorter(String str){
        char[] arr = str.toCharArray();
        Arrays.sort(arr);
        return new String(arr);        
    }
    public static void main(String[] args){
        Scanner sc =new Scanner(System.in);
        System.out.println("Enter a string: ");
        String str = sc.nextLine();
        int ch = 0;
        while(ch != 5){
            System.out.println("~~String Menu~~");
            System.out.println("1.Check Palindrome");
            System.out.println("2.Arrange in order");
            System.out.println("3.Reverse String");
            System.out.println("4.Concatenate(og + reverse)");
            System.out.println("5.Exit Menu");
            System.out.print("Enter your choice: ");
            ch = sc.nextInt();
            switch(ch){
                case 1: if(checkPalindrome(str)){
                            System.out.println("It is palindrome!");
                        } else {
                            System.out.println("Not Palindrome!");
                        }
                        break;
                case 2: System.out.println("Sorted String: "+sorter(str));
                        break;
                case 3: String rev = reverse(str);
                        System.out.println("Reversed String: "+rev);
                        break;
                case 4: String reve = reverse(str);
                        String conca = str.concat(reve);
                        System.out.println("Concatenated String: "+conca);
                        break;
                case 5: System.out.println("Exiting...");
                        break;
                default: System.out.println("Invalid choice try again!");
            }
        }
        sc.close();
    }
}
