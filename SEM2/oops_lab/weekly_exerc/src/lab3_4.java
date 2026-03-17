
class Die{
    int sideUp;

    int getSideUp(){
        return sideUp;
    }

    void roll(){
        sideUp = (int)(Math.random() * 6) + 1;
    }
}

class DieDemo{
    void demo(){
        Die d1 = new Die();
        Die d2 = new Die();

        d1.roll();
        d2.roll();

        System.out.println("Die 1: " + d1.getSideUp());
        System.out.println("Die 2: " + d2.getSideUp());
        System.out.println("Sum: " + (d1.getSideUp() + d2.getSideUp()));
    }
}

public class lab3_4 {
 public static void main(String args[]){
    DieDemo dd = new DieDemo();
    dd.demo();
 }
}
