class Box{
    double height, width, depth;
    Box(double h, double w, double d){
        height = h;
        width = w;
        depth = d;
    }
    double showVolume(){
        return height*width*depth;
    }
}

public class boxVolume {
    public static void main(String[] args){
        Box b1 = new Box(2,2,2);
        double vol = b1.showVolume();
        System.out.println(vol);
    }
}
