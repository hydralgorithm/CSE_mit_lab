class Student{
    long regNum;
    String name;
    double subjectWiseMarks[];
    double totalMarks;
    String Grade;
    Student(){
        regNum = 0;
        name = "None";
        subjectWiseMarks = new double[0];
        totalMarks = 0;
        Grade = "F";
    }
    Student(long r,String n,double m[]){
        regNum = r;
        name = n;
        subjectWiseMarks = m;
    }

    void compute(){
        totalMarks = 0;
        for(double m : subjectWiseMarks){
            totalMarks += m;
        }
        
        if(totalMarks >= 90)
            Grade = "A";
        else if(totalMarks >= 80)
            Grade = "B";
        else if(totalMarks >= 70)
            Grade = "C";
        else if(totalMarks >= 60)
            Grade = "D";
        else if(totalMarks >= 50)
            Grade = "E";
        else
            Grade = "F";
    }

    void Display(){
        System.out.println("Reg No: " + this.regNum);
        System.out.println("Name: " + this.name);
        System.out.println("Total Marks: " + this.totalMarks);
        System.out.println("Grade: " + this.Grade);
        for(double m : subjectWiseMarks){
            System.out.print(m+" ");
        }
    }

}

public class studentDemo {
    public static void main(String args[]){
        Student s1 = new Student();
        Student s2 = new Student(1234, "Bola", new double[]{43,64,21,98});
        s1.compute();
        s1.Display();
        s2.compute();
        s2.Display();
    }
}
