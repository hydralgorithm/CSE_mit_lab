class Ssstudent{
    Subject[] subjects;
    int count;
    int total;
    double avg;
    Ssstudent(){
        this.subjects  = new Subject[5]; 
        this.total = 0;
        this.avg = 0.0;
    }
    class Subject{
        String subjectName; 
        int marks;
        Subject(String n){
            this.subjectName = n;
        }
        void assignMarks(int m){
            this.marks = m;
        }
        void display(){
            System.out.println("Subject: "+subjectName+" | Marks: "+marks);
        }
    }
    void addSubject(String name, int marks){
        subjects[count] = new Subject(name);
        subjects[count].assignMarks(marks);
        count++;
    }
    void compute(){
        for(int i=0; i<count; i++){
            total += subjects[i].marks;
        }
        avg = (float)total/count ;
    }
    void displayDetails(){
        System.out.println("~~ SUBJECT DETAILS ~~");
        for(int i=0; i<count; i++){
            subjects[i].display();
        }
        System.out.println();
        System.out.println("Total Marks: "+total);
        System.out.printf("Average Marks: %.2f\n",avg);
    }
}

public class pract5_1 {
    public static void main(String[] args){
        Ssstudent s = new Ssstudent();
        s.addSubject("PHY", 92);
        s.addSubject("CHM", 67);
        s.addSubject("CSE", 98);
        s.addSubject("APE", 34);
        s.compute();
        s.displayDetails();
    }
}
