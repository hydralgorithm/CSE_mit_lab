class NonIntResultExceptiion extends Exception{
    int n, d;
    NonIntResultExceptiion(int i, int j){
        this.n = i;
        this.d = j;
    }
    public String toString(){
        return "Result of "+n+"/"+d+" is non integer.";
    }
}
public class ExcDemo9 {
    public static void main(String[] args){
        int[] numer = {67,34,12,33,23,12,14};
        int[] denom = {2,4,0,2,4,0};
        for(int i=0; i<numer.length; i++){
            try{
                if(numer[i]%2 != 0){
                    throw new NonIntResultExceptiion(numer[i], denom[i]);
                }
                System.out.println(numer[i]+"/"+denom[i]+" is "+(numer[i]/denom[i]));
            } catch (ArithmeticException e){
                System.out.println("Cannot divide by zero!");
            } catch (ArrayIndexOutOfBoundsException e){
                System.out.println("Out of limits array index!");
            } catch (NonIntResultExceptiion e){
                System.out.println(e);
            }
        }
    }
}
