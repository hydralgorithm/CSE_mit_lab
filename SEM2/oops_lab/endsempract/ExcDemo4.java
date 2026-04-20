public class ExcDemo4 {
    public static void main(String[] args){
        int[] numer = {67,34,52,53,87,4,20,10,6};
        int[] denom = {2,4,0,3,4,0,13};
        for(int i=0;i<numer.length;i++){
            try{
                System.out.println(numer[i]+"/"+denom[i]+" is "+(numer[i]/denom[i]));
            } catch (ArithmeticException e){
                System.out.println("Cannot divide by 0!");
            } catch (ArrayIndexOutOfBoundsException e){
                System.out.println("Array index out of bounds!");
            }
        }
    }
}
