class STUDENT{
    String name;
    int id;
    double mark;
    STUDENT(){
        this.name = "none";
        this.id = 0;
        this.mark = 0.0;
    }
    STUDENT(String n, int id, double m){
        this.name = n;
        this.id = id;
        this.mark = m;
    }
    void display(){
        System.out.println("Student name: " + name);
        System.out.println("Student id: " + id);
        System.out.println("Student mark: " + mark);
        System.out.println();
    }
}

public class lab4_1 {
    public static void main(String[] args){
        STUDENT s1 = new STUDENT();
        STUDENT s2 = new STUDENT("Boby",101,46.8);
        s1.display();
        s2.display();
    }
}
