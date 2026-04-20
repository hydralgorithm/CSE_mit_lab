class Students {
    private String name;
    private int age;

    public Students(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public void registerStudent(String name, int age) {
        if (age < 18 || age > 60) {
            throw new IllegalArgumentException(
                "Age must be between 18 and 60. Given age: " + age);
        }
        System.out.println("Welcome, " + name + " of age " + age + ".");
    }
}

public class lab10_1 {
    public static void main(String[] args) {
        Students s1 = new Students("Alice", 34);
        Students s2 = new Students("John", 14);
        Students s3 = new Students("Bob", 67);

        try {
            s1.registerStudent("Alice", 34);
            s2.registerStudent("John", 14);
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        }

        try {
            s3.registerStudent("Bob", 67);
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        }
    }
}