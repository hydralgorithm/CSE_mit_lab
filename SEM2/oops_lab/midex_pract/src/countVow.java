public class countVow {
    public static int countVow(String str){
        int count=0;
        String vowels = "AEIOUaeiou";
        for(int i=0; i< str.length(); i++){
            char ch = str.charAt(i);
            if(vowels.indexOf(ch) != -1){
                count++;
            }
        }
        return count;
    }
    public static void main(String args[]){
        String str = "Hey bro";
        int vowelCount = countVow(str);
        System.out.println("Vowels: "+vowelCount);
    }
}
