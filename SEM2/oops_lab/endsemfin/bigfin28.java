package SEM2.oops_lab.endsemfin;
import java.util.Scanner;

public class bigfin28 {
    static boolean hasDigit(String s){
        for(char ch: s.toCharArray()){
            if(Character.isDigit(ch))
                return true;
        }
        return false;
    }
    static void sorter(String[] words){
        for(int i=0; i<words.length-1;i++){
            for(int j=i+1; j<words.length; j++){
                if(words[i].compareTo(words[j])>0){
                    String temp = words[i];
                    words[i] = words[j];
                    words[j] = temp;
                }
            }
        }
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        if(hasDigit(str)){
            System.out.println("DIGIT FOUND");
        } else {
            String[] words = str.split(" ");
            sorter(words);
            for(String w: words){
                System.out.print(w+" ");
            }
            System.out.println();
        }
    }
}
