class Counter{
    static int count;
    Counter(){
        count++;
    }
    static void showCount(){
        System.out.println("Number of objects created: "+count);
    }
}

public class lab4_4 {
    public static void main(String[] args){
        Counter c1 =new Counter();
        Counter c2 =new Counter();
        Counter.showCount();
        Counter c3 =new Counter();
        Counter c4 =new Counter();
        Counter c5 =new Counter();
        Counter.showCount();
    }
}
