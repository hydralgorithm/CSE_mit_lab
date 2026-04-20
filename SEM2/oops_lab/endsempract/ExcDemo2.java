class excTest{
    static void genException(){
        int[] arr = new int[5];
        arr[7] = 6;
    }
}
public class ExcDemo2 {
    public static void main(String args[]){
        try{
            excTest.genException();
        }
        catch (ArrayIndexOutOfBoundsException e){
            System.out.println("Error: "+e);
        }
    }
}
