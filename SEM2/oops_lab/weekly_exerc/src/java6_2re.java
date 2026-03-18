class Employee{
    String name;
    Employee(String n){
        this.name = n;
    }
    String formatEmployeeName(){
        String[] words = name.split(" ");
        String result = "";
        for(int i=0; i<words.length; i++){
            if(words[i].length()>0){
                result += Character.toUpperCase(words[i].charAt(0))+words[i].substring(1).toLowerCase();
            }
            if(i < words.length-1){
                result+=" ";
            }
        }
        return result;
    }
    String generateEmail(){
        String formatted = formatEmployeeName().toLowerCase();
        String[] namesplit = formatted.split(" ");
        if(namesplit.length == 1){
            return namesplit[0]+"@email.com";
        } else {
            return namesplit[0].charAt(0) +namesplit[1]+"@example.com";
        }
    }
}

public class java6_2re {
    public static void main(String[] args){
        Employee e = new Employee("bOBbi lee");
        System.out.println(e.formatEmployeeName());
        System.out.println(e.generateEmail());
    }
}
