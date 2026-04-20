class Studenta{
    public static double calculateAverage(int totalMarks, int numberOfSubjects){
        if(totalMarks == 0 ){
            throw new ArithmeticException("Total Marks must not be zero!");
        }
        if(numberOfSubjects == 0){
            throw new ArithmeticException("Num of sub cannot be zero since will cause 0 division error!");
        }
        return (double)totalMarks/numberOfSubjects;
    }
}
public class lab10_3 {
    public static void main(String[] args){
        int[] total = {320,450,0,300,0,250,174};
        int[] subnum = {5,0,4,6};
        for(int i=0; i<total.length; i++){
            try{
                double avg = Studenta.calculateAverage(total[i], subnum[i]);
                System.out.println("Average = "+avg);
            } catch(ArithmeticException e){
                System.out.println(e.getMessage());
            } catch(ArrayIndexOutOfBoundsException e){
                System.out.println("Element not found!");
            }
        }
    }    
}
