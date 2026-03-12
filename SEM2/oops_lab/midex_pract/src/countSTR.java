public class countSTR {
    public static void main(String args[]){
        String str = "hello";
        char ch = 'l';
        int count = 0;
        int n = str.length();
        for(int i=0; i<n; i++){
            if(str.charAt(i) == ch){
                count++;
            }
        }
        System.out.println("No. of occurence of "+ch+" is: "+count);
    }
}
