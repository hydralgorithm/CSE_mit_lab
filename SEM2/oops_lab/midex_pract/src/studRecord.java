import java.util.Scanner;

class Student{
    String name;
    int rollno;
    double marks;
    Student(String n, int r, double m){
        this.name = n;
        this.rollno = r;
        this.marks = m;
    }

    void display(){
        System.out.println("Name: "+name);
        System.out.println("Roll : "+rollno);
        System.out.println("Marks: "+marks);
    }
}
public class studRecord {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter no. of students: ");
        int numOfStud = sc.nextInt();
        sc.nextLine();
        Student[] students = new Student[numOfStud];

        for(int i=0; i<numOfStud;i++){
            System.out.println("Enter Stud "+(i+1)+" Details:");
            System.out.print("Stud name: ");
            String n = sc.nextLine();
            System.out.print("Stud Roll: ");
            int r = sc.nextInt();
            System.out.print("Stud Marks: ");
            double m = sc.nextDouble();
            sc.nextLine();
            students[i] = new Student(n, r, m);
        }
        sc.close();
        System.out.println("Display records:");
        // for(int i=0; i<numOfStud;i++){
        //     System.out.println("Stud "+(i+1)+" details:");
        //     System.out.println("Name: "+students[i].name);
        //     System.out.println("Roll no: "+students[i].rollno);
        //     System.out.println("Marks: "+students[i].marks);
        // }
        for(Student s: students){
            s.display();;
        }
    }
}
