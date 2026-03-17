class Length{
    double inch, feet;
    Length(double i, double f){
        inch = i;
        feet = f;
    }
    void displayLength(){
        System.out.println("Length = "+feet+"feet");
        System.out.println("Length = "+inch+"inch");
    }
    void addLnegth(){
        this.feet = feet + (inch/12);
        this.inch = inch + (12*feet);
    }
}

public class overLoad {
    public static void main(String args[]){
        Length l = new Length(10,10 );
        l.displayLength();
        l.addLnegth();
        l.displayLength();
    }
}
