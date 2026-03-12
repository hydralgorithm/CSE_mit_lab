import java.util.jar.Attributes.Name;

class Course{
    String name;
    int code;
    int maxEnrol;
    Course(String n, int c, int m){
        this.name = n;
        this.code = c;
        this.maxEnrol = m;
    }
    void displayInfo(){
        System.out.println("Name: "+name+" Code: "+code+" Max Enrollment: "+maxEnrol);
    }
}

public class courseManage {
    static Course[] courses = new Course[5];
    static int courseCount = 0;

    public static void main(String args[]){
        addCourse("Math", 123, 45);
        addCourse("CSE", 342, 67);
        System.out.println("All courses:");
        displayAll();
        System.out.println("Course with code 342:");
        findCoursebyCode(342);
    }

    static void addCourse(String n, int c, int m){
        if(courseCount<courses.length){
            courses[courseCount++] = new Course(n, c, m);
        } else {
            System.out.println("Course arr full");
        }
    }

    static void displayAll(){
        for(int i=0; i<courseCount; i++){
            courses[i].displayInfo();
        }
    }

    static void findCoursebyCode(int id){
        for(int i=0; i < courseCount; i++){
            if(courses[i].code == id){
                System.out.println(courses[i].name+" has code "+ courses[i].code);
            }
        }
    }
}
