class Swapper{
    int x,y;
    Swapper(int a,int b){
        x = a;
        y = b;
    }
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    void swap(){
        int temp = x;
        x = y;
        y = temp;
    }
}

public class swappin {
    public static void main(String args[]){
        Swapper s = new Swapper(6,7);
        System.out.println(s.getX()+" & "+s.getY());
        s.swap();
        System.out.println(s.getX()+" & "+s.getY());
    }
}
