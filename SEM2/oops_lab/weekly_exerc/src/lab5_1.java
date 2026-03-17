class StudentDemo {
    String studentName;
    Subject[] subjects;

    StudentDemo(String n, int count) {
        this.studentName = n;
        this.subjects = new Subject[count];
    }

    class Subject {
        String subjectName;
        double marks;

        Subject(String n, double m) {
            assign(n, m);
        }

        void assign(String n, double m) {
            subjectName = n;
            marks = m;
        }

        void displaySubDetail() {
            System.out.println("Subject Name: " + subjectName + " | Marks: " + marks);
        }
    }

    void addSubject(int index, String name, double marks) {
        if (index < 0 || index >= subjects.length) {
            System.out.println("Invalid subject index.");
            return;
        }
        subjects[index] = new Subject(name, marks);
    }

    double calculateTotal() {
        double total = 0;
        for (Subject s : subjects) {
            if (s != null) {
                total += s.marks;
            }
        }
        return total;
    }

    double calculateAverage() {
        int filled = 0;
        double total = 0;
        for (Subject s : subjects) {
            if (s != null) {
                total += s.marks;
                filled++;
            }
        }
        if (filled == 0) {
            return 0;
        }
        return total / filled;
    }

    void displayStudentDetails() {
        System.out.println("Student Name: " + studentName);
        System.out.println("Subject Details:");
        for (Subject s : subjects) {
            if (s != null) {
                s.displaySubDetail();
            }
        }
        System.out.println("Total Marks: " + calculateTotal());
        System.out.println("Average Marks: " + calculateAverage());
    }
}

public class lab5_1 {
    public static void main(String[] args) {
        StudentDemo st = new StudentDemo("Bobby", 4);

        st.addSubject(0, "Math", 82);
        st.addSubject(1, "Physics", 76);
        st.addSubject(2, "Chemistry", 88);
        st.addSubject(3, "English", 91);

        st.displayStudentDetails();
    }
}
