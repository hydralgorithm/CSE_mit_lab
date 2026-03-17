public class paliStr {
    public static void main(String args[]){
        String str = "madama";
        boolean isPali = true;

        int start = 0;
        int end = str.length()-1;
        while(start < end){
            if(str.charAt(start) != str.charAt(end)){
                isPali = false;
                break;
            }
            start++;
            end--;
        }
        System.out.println(isPali);
    }
}
