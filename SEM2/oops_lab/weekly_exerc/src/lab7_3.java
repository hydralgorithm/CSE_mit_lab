class Building {
    double squareFootage;
    int stories;

    Building() {                          // overloaded: no-arg
        this.squareFootage = 0;
        this.stories = 0;
    }

    Building(double sqft, int s) {        // overloaded: full
        this.squareFootage = sqft;
        this.stories = s;
    }

    void displayDetails() {
        System.out.println("Square Footage: " + squareFootage);
        System.out.println("Stories: " + stories);
    }
}

class House extends Building {
    int bedroomNum, bathNum;

    House() {                             // overloaded: no-arg
        super();
        this.bedroomNum = 0;
        this.bathNum = 0;
    }

    House(double sqft, int s, int bed, int bath) {   // overloaded: full
        super(sqft, s);
        this.bedroomNum = bed;
        this.bathNum = bath;
    }

    @Override
    void displayDetails() {
        super.displayDetails();
        System.out.println("Bedrooms: " + bedroomNum);
        System.out.println("Bathrooms: " + bathNum);
    }
}

class School extends Building {
    int classNum;
    String gradeLvl;

    School() {                            // overloaded: no-arg
        super();
        this.classNum = 0;
        this.gradeLvl = "Unknown";
    }

    School(double sqft, int s, int c, String gl) {   // overloaded: full
        super(sqft, s);
        this.classNum = c;
        this.gradeLvl = gl;
    }

    @Override
    void displayDetails() {
        super.displayDetails();
        System.out.println("Classrooms: " + classNum);
        System.out.println("Grade Level: " + gradeLvl);
    }
}

public class lab7_3 {
    public static void main(String[] args) {

        System.out.println("--- Building (no-arg) ---");
        Building b1 = new Building();
        b1.displayDetails();

        System.out.println("\n--- Building (full) ---");
        Building b2 = new Building(25, 3);
        b2.displayDetails();

        System.out.println("\n--- House (no-arg) ---");
        House h1 = new House();
        h1.displayDetails();

        System.out.println("\n--- House (full) ---");
        House h2 = new House(45, 2, 3, 2);
        h2.displayDetails();

        System.out.println("\n--- School (no-arg) ---");
        School s1 = new School();
        s1.displayDetails();

        System.out.println("\n--- School (full) ---");
        School s2 = new School(75, 4, 30, "High School");
        s2.displayDetails();
    }
}