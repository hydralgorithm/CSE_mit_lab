class Student{
    String sname;
    int[] marks_array;
    int total;
    double avg;
    void assign(String name, int[] marks){
        this.sname = name;
        this.marks_array = marks;
        this.total = 0;
        this.avg = 0.0;
    }
    void display(){
        System.out.println("Student Name: "+sname);
        System.out.println("Student marks: ");
        for(int n : marks_array){
            System.out.print(n+" ");
        }
        System.out.println();
        System.out.println("Total Marks: "+total);
        System.out.println("Average marks: "+avg);
    }
    void compute(){
        for(int n : marks_array){
            total += n;
        }
        avg = (double) total / marks_array.length;
    }
}

public class lab3_1 {
    public static void main(String[] args){
        Student s1 = new Student();
        int[] arr = {56,32,49,93}; 
        s1.assign("Bobby", arr);
        s1.compute();
        s1.display();
    }
}
