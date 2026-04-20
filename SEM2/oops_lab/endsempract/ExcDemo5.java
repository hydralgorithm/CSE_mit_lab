public class ExcDemo5 {
    public static void main(String[] args){
        int[] numer = {23,41,56,32,12,87,59,10};
        int[] denom = {2,5,0,3,0,12};
        for(int i=0; i<numer.length;i++){
            try{
                System.out.println(numer[i]+"/"+denom[i]+" is "+(numer[i]/denom[i]));
            } catch (ArrayIndexOutOfBoundsException e){
                System.out.println("Array index out of bound!");
            } catch (Throwable e){
                System.out.println("Some error occurred");
            }
        }
    }
}
