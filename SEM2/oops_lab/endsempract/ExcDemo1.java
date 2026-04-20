public class ExcDemo1 {
    public static void main(String args[]){
        int[] arr = new int[5];
        try{
            arr[0] = 6;
        }
        catch (ArrayIndexOutOfBoundsException e){
            System.out.println("Array index out of bounds!");
            System.out.println("Error: "+e);
        }
        System.out.println("After Catch block!");
    }
}
