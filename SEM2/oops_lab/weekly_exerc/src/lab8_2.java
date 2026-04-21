interface Series{
    int getNext();
    void reset();
    void setStart(int x);
}
class ByTwos implements Series{
    int start, current;
    ByTwos(){
        this.start = 0;
        this.current = 0;
    }
    @Override
    public int getNext(){
        current += 2;
        return current;
    }
    @Override
    public void reset(){
        current = start;
    }
    @Override
    public void setStart(int x){
        start = x;
        current = x;
    }
}
public class lab8_2 {
    public static void main(String[] args){
        ByTwos bt = new ByTwos();
        System.out.println("--Default Series--");
        for(int i=0; i<5; i++){
            System.out.print(bt.getNext()+" ");
        }
        System.out.println();

        bt.reset();
        for(int i=0; i<5; i++){
            System.out.print(bt.getNext()+" ");
        }
        System.out.println();

        bt.setStart(10);
        for(int i=0; i<5; i++){
            System.out.print(bt.getNext()+" ");
        }
        System.out.println();

        Series s;
        s = new ByTwos();
        
        s.setStart(20);
        for(int i=0; i<5; i++){
            System.out.print(s.getNext()+" ");
        }
        System.out.println();
    }
}
