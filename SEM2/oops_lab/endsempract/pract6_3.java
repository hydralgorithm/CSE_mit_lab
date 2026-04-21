class Sstudent{
    String name;
    Sstudent(String n){
        this.name = n;
    }
    String extractInitials(){
        String[] words = name.split(" ");
        String result = "";
        for(int i=0; i<words.length; i++){
            result += Character.toUpperCase(words[i].charAt(0));
        }
        return result;
    }
    String removeWhiteSpace(){
        String[] rmwhite = name.split(" ");
        String result = "";
        for(int i=0; i<rmwhite.length; i++){
            result += rmwhite[i];
        }
        return result;
    }
    
}

public class pract6_3 {
    public static void main(String[] args){
        String str = "Boby Lee";
        Sstudent s = new Sstudent(str);
        System.out.println(s.extractInitials());
        System.out.println(s.removeWhiteSpace());
    }
}
