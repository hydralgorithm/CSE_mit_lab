import java.util.Scanner;

class Student {
    int rollNum;
    int marks;
    Scanner sc = new Scanner(System.in);

    void getRollNum() { 
        System.out.print("Enter Roll No: ");
        rollNum = sc.nextInt(); 
    }
    void putRollNum() { System.out.print("Roll: " + rollNum); }

    void getMarks() { 
        System.out.print("Enter Marks: ");
        marks = sc.nextInt(); 
    }
    void putMarks() { System.out.print(" | Marks: " + marks); }
}

interface Sports {
    void putSportsScore(int score);
}

class Result extends Student implements Sports {
    int sportsScore;

    @Override
    public void putSportsScore(int score) {
        this.sportsScore = score;
    }

    void display() {
        putRollNum();
        putMarks();
        System.out.println(" | Sports: " + sportsScore + 
        " | Total: " + (marks + sportsScore));
    }
}

public class lab8_3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Result r = new Result();
        r.getRollNum();
        r.getMarks();
        System.out.print("Enter Sports Score: ");
        r.putSportsScore(sc.nextInt());
        r.display();
    }
}