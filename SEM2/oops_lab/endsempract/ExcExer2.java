class Student1{
    public static double calcAvg(int totalmarks, int subnum){
        if(subnum == 0){
            throw new ArithmeticException("Error: Number of subjects cannot be zero as it will cause 0 division error!");
        }
        if(totalmarks == 0){
            throw new ArithmeticException("Total marks cannot be 0!");
        }
        return (double) totalmarks/subnum;
    }
}
public class ExcExer2 {
    public static void main(String args[]){
        try{
            double avg1 = Student1.calcAvg(340, 5);
            System.out.println("Avg marks 1: "+avg1);
            double avg2 = Student1.calcAvg(400, 0);
            System.out.println("Avg marks 2: "+avg2);
        } catch(ArithmeticException e){
            System.out.println(e.getMessage());
        }
        try{
            double avg3 = Student1.calcAvg(0, 300);
            System.out.println("Avg marks 3: "+avg3);
        } catch(ArithmeticException e){
            System.out.println(e.getMessage());
        }
    }
}
