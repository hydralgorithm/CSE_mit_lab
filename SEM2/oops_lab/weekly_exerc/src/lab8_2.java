interface Series {
    int getNext();
    void reset();
    void setStart(int start);
}

class ByTwos implements Series {
    int start, current;

    ByTwos() { start = 0; current = 0; }

    @Override
    public int getNext() {
        current += 2;
        return current;
    }

    @Override
    public void reset() { current = start; }

    @Override
    public void setStart(int start) {
        this.start = start;
        this.current = start;
    }
}

public class lab8_2 {
    public static void main(String[] args) {
        Series s = new ByTwos();

        System.out.print("Series from 0: ");
        for (int i = 0; i < 5; i++)
            System.out.print(s.getNext() + " ");

        s.reset();
        System.out.print("\nAfter reset: ");
        for (int i = 0; i < 5; i++)
            System.out.print(s.getNext() + " ");

        s.setStart(10);
        System.out.print("\nFrom 10: ");
        for (int i = 0; i < 5; i++)
            System.out.print(s.getNext() + " ");
    }
}