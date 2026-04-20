class Student{
    private String name;
    private int age;
    public Student(String n, int a){
        this.name = n;
        this.age = a;
    }
    public static void registerStudent(String name, int age){
        if (age<18 || age>60){
            throw new IllegalArgumentException("Error: Age must be between 18 and 60. Given age: "+age);
        } 
        System.out.println("Student registered successfully!\nWelcome, "+name+" of age "+age);
    }
}

public class ExcExer1 {
    public static void main(String[] args){
        try{
            Student.registerStudent("Alice", 26);
            Student.registerStudent("Bob", 16);
        } catch(IllegalArgumentException e){
            System.out.println(e.getMessage());
        }
        try{
            Student.registerStudent("JOE", 72);
        } catch(IllegalArgumentException e){
            System.out.println(e.getMessage());
        }
    }
}
