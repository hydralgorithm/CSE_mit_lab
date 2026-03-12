import java.util.Scanner;

public class revString {
    public static void main(String args[]){
        System.out.println("Enter string: ");
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        String words[] = str.split(" ");
        String rev = "";
        sc.close();
        for(String word: words){
            for(int i=word.length() - 1; i>=0 ; i--){
                rev += word.charAt(i);
            }
            rev += " ";
        }
        System.out.println(rev);
    }
}
