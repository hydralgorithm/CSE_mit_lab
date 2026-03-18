class Student implements Comparable<Student> {
    String name;
    
    Student(String n){
        this.name = n;
    }
    
    String extractInitials(){
        String[] words = name.split(" ");
        String extract = "";
        for(int i=0; i<words.length; i++){
            extract += Character.toUpperCase(words[i].charAt(0));
        }
        return extract;
    }
    
    String removeWhitespace(){
        String[] words = name.split(" ");
        String whiteRemove = "";
        for(int i=0; i<words.length; i++){
            whiteRemove += words[i];
        }
        return whiteRemove;
    }
    
    static void listBySubstring(Student[] students, String substring){
        System.out.println("\nStudents containing '" + substring + "':");
        for(Student s : students){
            if(s.name.contains(substring)){
                System.out.println(s.name);
            }
        }
    }
    
    static void sortAlphabetically(Student[] students){
        java.util.Arrays.sort(students);
        System.out.println("\nStudents sorted alphabetically:");
        for(Student s : students){
            System.out.println(s.name);
        }
    }
    
    @Override
    public int compareTo(Student other){
        return this.name.compareTo(other.name);
    }
}

public class lab6_3re {
    public static void main(String[] args){
        java.util.Scanner sc = new java.util.Scanner(System.in);
        
        System.out.print("Enter number of students: ");
        int n = sc.nextInt();
        sc.nextLine(); // consume newline
        
        Student[] students = new Student[n];
        
        System.out.println("Enter student names:");
        for(int i = 0; i < n; i++){
            System.out.print("Student " + (i+1) + ": ");
            String name = sc.nextLine();
            students[i] = new Student(name);
        }
        
        // Display all students with their initials and names without whitespace
        System.out.println("\n--- All Students ---");
        for(Student s : students){
            System.out.println("Name: " + s.name + " | Initials: " + s.extractInitials() + 
                             " | No spaces: " + s.removeWhitespace());
        }
        
        // List students containing a substring
        System.out.print("\nEnter substring to search: ");
        String substring = sc.nextLine();
        Student.listBySubstring(students, substring);
        
        // Sort students alphabetically
        Student.sortAlphabetically(students);
        
        sc.close();
    }
}
