package SEM2.oops_lab.endsemfin;

class Stuudent{
    public String name;
    public int marks;
    public static int graceMarks = 5;
    Stuudent(String n, int m){
        this.name = n;
        this.marks = m;
    }
    double normalizedScore(){
        return marks + graceMarks*0.5;
    }
    static Stuudent topper(Stuudent s1, Stuudent s2){
        return s1.normalizedScore()>=s2.normalizedScore()?s1:s2;
    }
}
class ResultProcessor{
    static void applyBonus(Stuudent s, double bonus){
        s.marks += (int)bonus;
    }
    static double classAverage(Stuudent[] arr){
        double sum = 0;
        for(Stuudent s:arr){
            sum += s.marks;
        }
        return sum/arr.length;
    }
}

public class bigfin27 {
    public static void main(String[] args){
        Stuudent[] stuudents = {
            new Stuudent("Alice", 80),
            new Stuudent("Bob", 72),
            new Stuudent("Jon",91)
        };
        ResultProcessor.applyBonus(stuudents[0], 3.7); // passing object
        for (Stuudent s : stuudents)
            System.out.println(s.name + ": " + s.normalizedScore());
        Stuudent t = Stuudent.topper(stuudents[0], stuudents[1]); // receiving
        System.out.println("Topper: " + t.name);
        System.out.println("Class avg: " +
        ResultProcessor.classAverage(stuudents));
    }
}
