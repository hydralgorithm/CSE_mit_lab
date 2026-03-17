class Box{
    double height;
    double width;
    double depth;
    double volume(){
        return height*width*depth;
    }
    void setDim(double h, double w, double d){
        height= h;
        width = w;
        depth = d;
    }
}

public class paramMethod {
    public static void main(String args[]){
        Box demobox = new Box();
        demobox.setDim(5,5,5);
        System.out.println("Volume = "+demobox.volume());
    }
}
