import java.util.Scanner;

class Employeee{
    String name;
    Employeee(String n){
        this.name = n;
    }
    String formatEmployeeName(){
        String[] words = name.toLowerCase().split("");
        String formatName = "";
        for(int i=0; i<words.length; i++){
            if(words[i].length()>0){
                formatName += Character.toUpperCase(words[i].charAt(0)) + words[i].substring(1);
                if(i < words.length-1) formatName += " ";
            }
        }
        return formatName;
    }
    String generateEmail(){
        String[] words = name.toLowerCase().split("");
        words[0] = words[0].substring(0,1);
        String result = "";
        for(int i=0; i<words.length; i++){
            result += words[i];
        }
        result += "@example.com";
        return result;
    }
}
public class pract6_2 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String str = "John Doe";
        Employee e = new Employee(str);
        System.out.println(e.formatEmployeeName());
        System.out.println(e.generateEmail());
        sc.close();
    }
}
