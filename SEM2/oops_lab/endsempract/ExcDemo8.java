// Throwable methods
class excTest{
    public static void genException(){
        int[] arr = new int[5];
        System.out.println("B4 error!");
        arr[12] = 3; 
        System.out.println("Im invincible!");
    }
}
public class ExcDemo8 {
    public static void main(String[] args){
        try{
            excTest.genException();
        } catch (ArrayIndexOutOfBoundsException e){
            System.out.println("Normal error message: \n"+e);
            System.out.println("Stack Trace:");
            e.printStackTrace();
            System.out.println("To string: \n"+e.toString());
        }
    }
}
