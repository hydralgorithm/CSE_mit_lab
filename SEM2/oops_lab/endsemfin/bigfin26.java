package SEM2.oops_lab.endsemfin;

class Sttudent{
    private static int counter=0;
    private int rollNo;
    private String name;
    private double[] marks;
    Sttudent(){
        counter++;
        this.rollNo = counter;
        this.name = "Unknown";
        this.marks = new double[5];
    }
    Sttudent(String n, double[] m){
        this();
        this.name = n;
        this.marks = m;
    }
    Sttudent(Sttudent s){
        this(s.name, new double[5]);
        for(int i=0; i<5; i++){
            this.marks[i] = s.marks[i];
        }
    }
    double avg(){
        double sum=0;
        for(double m: marks){ sum+=m; }
        return sum/marks.length;
    }
    void display(){
        System.out.println("Roll Number: "+rollNo+" | Name: "+name);
        System.out.print("Marks: ");
        for(double m:marks){
                System.out.print(m+" ");
        }
        System.out.println();
    }
    public int normalizedScore() {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'normalizedScore'");
    }
}
public class bigfin26 {
    public static void main(String[] args){
        Sttudent s1 = new Sttudent();
        double[] m = {45,92,12,86,24};
        Sttudent s2 = new Sttudent("Bob", m);
        Sttudent s3 = new Sttudent(s2);
        s1.display();
        s2.display();
        s3.display();
    }
}
