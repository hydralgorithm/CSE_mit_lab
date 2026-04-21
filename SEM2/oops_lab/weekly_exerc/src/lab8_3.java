class Studenthm{
    int rollnum;
    int[] marks;
    void getRollNum(int r){
        rollnum = r;
    }
    void putRollNum(){
        System.out.println("Roll Number: "+rollnum);
    }
    void getMarks(int[] m){
        int subnum = m.length;
        marks = new int[subnum];
        for(int i=0; i<subnum; i++){
            marks[i] = m[i];
        }
    }
    void putMarks(){
        System.out.print("Marks: ");
        for(int i=0; i<marks.length; i++){
            System.out.print(marks[i]+" ");
        }
        System.out.println();
    }
}
interface Sports{
    void putSportsScore(int score);
}
class Result extends Studenthm implements Sports{
    int sportsScore;
    @Override
    public void putSportsScore(int score){
        sportsScore = score;
    }
    void generateResult(){
        int total = 0;
        for(int m: marks){
            total += m;
        }
        double avg = (double)total/marks.length;
        int grandTotal = total + sportsScore;
        System.out.println("~~~RESULT~~~");
        putRollNum();
        putMarks();
        System.out.println("Total Marks: "+total);
        System.out.println("Average: "+avg);
        System.out.println("Sports Score: "+sportsScore);
        System.out.println("Grand Total: "+grandTotal);
        System.out.println();
    }
}

public class lab8_3 {
    public static void main(String[] args){
        Result r1 = new Result();
        r1.getRollNum(101);
        int m[] = {45,32,56,24};
        r1.getMarks(m);
        r1.putSportsScore(15);
        r1.generateResult();
    }
}
