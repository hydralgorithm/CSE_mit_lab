class Studentb{
    String sname;
    int[] marks;
    int subnum;
    int total;
    double avg;
    Studentb(String s, int[] m){
        this.sname = s;
        this.subnum = m.length;
        this.marks = new int[subnum];
        for(int i=0; i<subnum; i++){
            this.marks[i] = m[i];
        }
    }
    void compute(){
        total = 0;
        for(int i=0; i<subnum; i++){
            total += marks[i];
        }
        avg = (double)total/subnum;
    }
    void display(){
        System.out.println("Name: "+sname);
        for(int i=0; i<subnum; i++){
            System.out.println("Sub "+(i+1)+": "+marks[i]);
        }
        System.out.println("Total: "+total+" | Average: "+avg);
    }
}
class ScienceStudent extends Studentb{
    int practicalMarks;
    ScienceStudent(String n, int[] m, int p){
        super(n,m);
        this.practicalMarks = p;
    }
    @Override
    void compute(){
        total = 0;
        for(int m : marks){
            total += m;
        }
        total += practicalMarks;
        avg = (double)total/(subnum+1);
    }
    void displayPracticalMarks(){
        System.out.println("Practical Marks: "+practicalMarks);
    }
    @Override
    void display(){
        super.display();
        displayPracticalMarks();
    }
}
class ArtsStudent extends Studentb{
    String electiveSubject;
    ArtsStudent(String n, int[] m, String e){
        super(n,m);
        this.electiveSubject = e;
    }
    @Override
    void display(){
        super.display();
        System.out.println("Elective Subject: "+electiveSubject);
    }
}
public class lab7_1{
    public static void main(String[] args){
        int[] m1 = {72,34,65,67,81,23};
        Studentb sb = new Studentb("Ravi",m1);
        sb.compute();
        System.out.println("STUDENT DETAILS:");
        sb.display();
        int[] m2 = {24,62,16,85,37,90};
        ScienceStudent sc = new ScienceStudent("Bobi",m2,67);
        sc.compute();
        System.out.println("SCIENCE STUDENT INFO:");
        sc.display();
        int[] m3 = {45,89,56,62,71,12};
        ArtsStudent ar = new ArtsStudent("Leelee", m3, "Upper elective");
        ar.compute();
        ar.display();

        // DYNAMIC POLYMORPHISM
        Studentb d1 = new ScienceStudent("Robbie", m2, 67);
        d1.compute();
        d1.display();
        Studentb d2 = new ArtsStudent("Monkey", m3, "HEHE");
        d2.compute();
        d2.display();
    }
}