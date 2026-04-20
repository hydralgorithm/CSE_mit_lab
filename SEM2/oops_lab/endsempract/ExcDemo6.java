// Nested try
public class ExcDemo6 {
    public static void main(String[] args){
        int numer[] = {67,32,20,35,15,16,72,12};
        int denom[] = {2,0,4,3,0,8,0};
        try{
            for(int i=0;i<numer.length;i++){
                try{
                    System.out.println(numer[i]+"/"+denom[i]+" is "+(numer[i]/denom[i]));
                }catch (ArithmeticException e){
                    System.out.println("Cannot divide by 0!");
                }
            }
        } catch(ArrayIndexOutOfBoundsException e){
            System.out.println("Array out of limits!");
        }
    }
}
