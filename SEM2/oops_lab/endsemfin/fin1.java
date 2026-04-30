package SEM2.oops_lab.endsemfin;
import java.util.Scanner;

public class fin1 {
    private static boolean containsDigits(String str){
        for(char ch : str.toCharArray()){
            if(Character.isDigit(ch)){
                return true;
            }
        }
        return false;
    }
    private static void sortWords(String[] words){
        for(int i=0; i<words.length-1; i++){
            for(int j=i+1; j<words.length;j++){
                if (words[i].compareTo(words[j]) > 0) {
                    String temp = words[i];
                    words[i] = words[j];
                    words[j] = temp;
                }
            }
        }
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a sentence: ");
        String str = sc.nextLine();
        if(containsDigits(str)){
            System.out.println("Digits found!");
        } else {
            System.out.println("Digits not found");
        }
        String[] words = str.split(" ");
        sortWords(words);
        System.out.println("Sorted words:");
        for(String word : words){
            System.out.println(word);
        }
        sc.close();
    }
}
