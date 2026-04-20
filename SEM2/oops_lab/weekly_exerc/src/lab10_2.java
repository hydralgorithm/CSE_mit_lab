class CourseFullException extends Exception{
    int limit;
    CourseFullException(int l){
        this.limit = l;
    }
    public String toString(){
        return "Course of limit "+limit+" is full.";
    }
}
class Courses{
    private String courseName;
    private int capacity, enrolledStudents;
    public Courses(int capacity, int enrolled){
        this.capacity = capacity;
        this.enrolledStudents = enrolled;
    }
    public void enrollStudent(String courseName) throws CourseFullException{
        if(enrolledStudents >= capacity){
            throw new CourseFullException(capacity);
        }
        System.out.println("Course "+courseName+" successfully registered! Current number of enrolled students: "+(++enrolledStudents));
    }
}
public class lab10_2 {
    public static void main(String[] args){
        Courses c = new Courses(3,0);
        try{
            c.enrollStudent("CS101");
            c.enrollStudent("PHY201");
            c.enrollStudent("MAT301");
            c.enrollStudent("CHM101");
        } catch (CourseFullException e){
            System.out.println(e);
        }
    }
}
