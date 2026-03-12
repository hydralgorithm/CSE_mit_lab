public class charStr {
    public static void main(String args[]){
        String str = "hello";
        char[] chArr = str.toCharArray();
        chArr[0] = 'H';
        String newStr = new String(chArr);
        System.out.println(newStr); 
    }
}
