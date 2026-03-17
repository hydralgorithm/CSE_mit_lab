class Smartphone{
    String brand;
    Smartphone(String b){
        this.brand = b;
    }
    class Processor{
        int cores;
        double clockSpeed;
        Processor(int c, double cs){
            this.cores = c;
            this.clockSpeed = cs;
        }
        void displayProcessorDetails(){
            System.out.println("Brand: "+ brand);
            System.out.println("Cores: "+ cores);
            System.out.println("Clockspeed: "+ clockSpeed);
        }
    }
}

public class phone {
    public static void main(String args[]){
        Smartphone s = new Smartphone("Nokia");
        Smartphone.Processor p = s.new Processor(4,456);
        p.displayProcessorDetails();

    }
}
