public class ExcDemo3 {
    public static void main(String[] args){
        int[] numer = {43,24,0,67,12,20};
        int[] denom = {12,13,2,0,43,0};
        for(int i=0; i<numer.length; i++){
            try{
                System.out.println(numer[i]+"/"+denom[i]+" is "+(numer[i]/denom[i]));   
            } 
            catch (ArithmeticException e){
                System.out.println("Numerator cannot be divided by zero!");
                // System.out.println("Error: "+e);
            }
        }
    }
}
