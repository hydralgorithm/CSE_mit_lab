class Building {
    double sqft;
    int stories;

    Building() {
        this.sqft = 0;
        this.stories = 0;
    }

    Building(double sqft, int stories) {
        this.sqft = sqft;
        this.stories = stories;
    }

    void display() {
        System.out.println("Sqft: " + sqft + " | Stories: " + stories);
    }
}

class House extends Building {
    int bedrooms, baths;

    House() {
        super();
        this.bedrooms = 0;
        this.baths = 0;
    }

    House(double sqft, int stories, int bedrooms, int baths) {
        super(sqft, stories);
        this.bedrooms = bedrooms;
        this.baths = baths;
    }

    @Override
    void display() {
        super.display();
        System.out.println("Bedrooms: " + bedrooms + " | Baths: " + baths);
    }
}

class School extends Building {
    int classrooms;
    String gradeLevel;

    School() {
        super();
        this.classrooms = 0;
        this.gradeLevel = "None";
    }

    School(double sqft, int stories, int classrooms, String gradeLevel) {
        super(sqft, stories);
        this.classrooms = classrooms;
        this.gradeLevel = gradeLevel;
    }

    @Override
    void display() {
        super.display();
        System.out.println("Classrooms: " + classrooms + " | Grade: " + gradeLevel);
    }
}

public class lab7_3 {
    public static void main(String[] args) {
        // Default constructors
        House h1 = new House();
        System.out.println("-- House (default) --");
        h1.display();

        // Parameterized constructors
        House h2 = new House(1500.0, 2, 3, 2);
        System.out.println("-- House --");
        h2.display();

        School sc1 = new School();
        System.out.println("-- School (default) --");
        sc1.display();

        School sc2 = new School(8000.0, 3, 20, "Elementary");
        System.out.println("-- School --");
        sc2.display();

        // Dynamic Polymorphism
        Building[] arr = {h2, sc2};
        System.out.println("\n-- Dynamic Polymorphism --");
        for (Building b : arr) b.display();
    }
}