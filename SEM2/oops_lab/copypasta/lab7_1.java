class Student {
    String sname;
    int[] marks;
    int total;
    double avg;
    int n;

    Student(String name, int n) {
        this.sname = name;
        this.n = n;
        marks = new int[n];
    }

    void assign(int[] m) {
        marks = m;
    }

    void compute() {
        total = 0;
        for (int m : marks) total += m;
        avg = (double) total / n;
    }

    void display() {
        System.out.println("Name: " + sname + 
        " | Total: " + total + " | Avg: " + avg);
    }
}

class ScienceStudent extends Student {
    int practicalMarks;

    ScienceStudent(String name, int n, int pm) {
        super(name, n);
        this.practicalMarks = pm;
    }

    @Override
    void compute() {
        total = 0;
        for (int m : marks) total += m;
        total += practicalMarks;
        avg = (double) total / (n + 1);
    }

    void displayPracticalMarks() {
        System.out.println("Practical Marks: " + practicalMarks);
    }

    @Override
    void display() {
        super.display();
        displayPracticalMarks();
    }
}

class ArtsStudent extends Student {
    String electiveSubject;

    ArtsStudent(String name, int n, String elective) {
        super(name, n);
        this.electiveSubject = elective;
    }

    @Override
    void display() {
        super.display();
        System.out.println("Elective: " + electiveSubject);
    }
}

public class lab7_1 {
    public static void main(String[] args) {
        Student s = new Student("Alice", 3);
        s.assign(new int[]{80, 75, 70});
        s.compute();
        s.display();

        ScienceStudent ss = new ScienceStudent("Bob", 3, 45);
        ss.assign(new int[]{85, 90, 88});
        ss.compute();
        ss.display();

        ArtsStudent as = new ArtsStudent("Carol", 3, "Music");
        as.assign(new int[]{78, 82, 80});
        as.compute();
        as.display();

        // Dynamic Polymorphism
        Student[] arr = {s, ss, as};
        System.out.println("\n-- Dynamic Polymorphism --");
        for (Student st : arr) st.display();
    }
}

