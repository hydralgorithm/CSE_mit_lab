class Box{
    double width;
    double height; 
    double depth;
    void vol(){
        double volu = height*width*depth;
        System.out.println(volu+ " : with method");
    }
}

public class boxVolume {
    public static void main(String args[]){
        Box b1 = new Box();
        b1.height = 10;
        b1.width = 10;
        b1.depth = 10;
        double volume = b1.height * b1.width * b1.depth;
        System.out.println(volume);
        // Object reference variable assigning
        Box b2 = b1;
        double volume2 = b2.height * b2.width * b2.depth;
        System.out.println(volume+": with ref");
        
        b1.vol();
    }
}
