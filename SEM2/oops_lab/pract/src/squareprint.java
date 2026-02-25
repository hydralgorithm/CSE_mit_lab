public class squareprint {
    public static void main(String[] args){
        int total = 0;
        for(int i=1; i<=20; i++){
            System.out.println(i*i);
            total += (i*i);
        }
        System.out.println("Total of Squares: "+total);
    }
}
