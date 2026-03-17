class Car{
    String model;
    int productionNumber;
    static int totalCars = 0;

    Car(String model, int prnum){
        this.model = model;
        this.productionNumber = prnum;
        totalCars++;
    }

    static void displayProductionSummary(){
        System.out.println("Total cars produced: "+totalCars);
    }
}

public class automobile {
    public static void main(String args[]){
        Car c1 = new Car("BMW",131);
        Car c2 = new Car("Kia",132);
        Car c3 = new Car("Hyundai",133);
        Car.displayProductionSummary();
    }
}
