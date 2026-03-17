class STUDENT{
    Subject[] subjects;
    int count;
    double total;
    double avg;
    STUDENT(int n){
        this.count = n;
        this.total = 0;
        this.avg = 0;
        this.subjects = new Subject[count];
    }
    void addSubject(int idx,String n, double m){
        subjects[idx] = new Subject(n,m); 
    }
    void compute() {
        total = 0; // reset first
        for (Subject s : subjects) {
            if (s != null) {
                total += s.marks;
            }
        }
        avg = total / subjects.length;
    }
    void displayDetails() {
        compute();
        System.out.println("Subject details:");
        for (Subject s : subjects) {
            if (s != null) {
                s.displayDetails();
            }
        }
        System.out.println("Total: " + total);
        System.out.println("Average: " + avg);
    }
    class Subject{
        String subjectName;
        double marks;
        Subject(String n, double m){
            assign(n,m);
        }
        void assign(String n, double m){
            this.subjectName = n;
            this.marks = m;
        }
        void displayDetails(){
            System.out.println("Subject: "+subjectName+" Marks: "+marks);
        }
    }

}
public class lab5_1self {
    public static void main(String[] args){
        STUDENT s = new STUDENT(4);
        s.addSubject(0,"Physics", 79);
        s.addSubject(1,"Physics", 79);
        s.addSubject(2,"Physics", 79);
        s.addSubject(3,"Physics", 79);
        s.displayDetails();
    }
}
