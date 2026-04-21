import java.util.Scanner;

class IncorrectIdException extends Exception{
    public String toString(){
        return "Invalid! ID not matching!";
    }
}
interface TicketManage{
    void bookTicket(int id, String name, int age, double fare, String ticketType);
    void cancelTicket(int id) throws IncorrectIdException;
    void displayDetails();
}
class Passenger{
    int id, age;
    double fare;
    String name;
    String ticketType;
    Passenger(int id, String n, int age, double f, String tt){
        this.id = id;
        this.name = n;
        this.age = age;
        this.fare = f;
        this.ticketType = tt;
    }
}
class Train{
    int trainNumber;
    String trainType, departureTime, source, destination;
    Passenger[] passengers;
    int passengerCount = 0;
    Train(int tn, String tt, String dt, String s, String d){
        this.trainNumber = tn;
        this.trainType = tt;
        this.departureTime = dt;
        this.source = s;
        this.destination = d;
        this.passengers = new Passenger[5];
    }
}
class LocalTrain extends Train implements TicketManage{
    LocalTrain(int tn, String dt, String s, String d){
        super(tn,"Local",dt,s,d);
    }
    @Override
    public void bookTicket(int id, String name, int age, double fare, String ticketType){
        if(passengerCount >= 5){
            System.out.println("Train is full!");
            return;
        } 
        passengers[passengerCount++] = new Passenger(id,name,age,fare,ticketType);
        System.out.println("Ticket Booked! Passenger id: "+id);
    }
    @Override
    public void cancelTicket(int id) throws IncorrectIdException{
        for(int i=0; i<passengerCount; i++){
            if(id == passengers[i].id){
                System.out.println("Ticket cancelled for "+passengers[i].name);
                for(int j = i; j< passengerCount-1; j++){
                    passengers[j] = passengers[j+1];
                }
                passengers[--passengerCount] = null;
                return;
            }
        }
        throw new IncorrectIdException();
    }
    @Override
    public void displayDetails(){
        System.out.println("~~~ LOCAL TRAIN ~~~");
        System.out.println("Train No.: "+trainNumber+"| Train Type: "+trainType);
        System.out.println("Departure: "+departureTime+"| Source: "+source);
        System.out.println("Destination: "+destination);
        System.out.println("--- PASSENGER DETAILS ---");
        for(int i=0; i<passengerCount; i++){
            System.out.println("ID: "+passengers[i].id+" | Name: "+passengers[i].name+" | Age: "+passengers[i].age);
            System.out.println("Fare: Rs"+passengers[i].fare+" | Type: "+passengers[i].ticketType);
        }
    } 
}
class ExpressTrain extends Train implements TicketManage{
    ExpressTrain(int tn, String dt, String s, String d){
        super(tn,"Express",dt,s,d);
    }
    @Override
    public void bookTicket(int id, String name, int age, double fare, String ticketType){
        if(passengerCount >= 5){
            System.out.println("Train full!");
            return;
        }
        passengers[passengerCount++] = new Passenger(id,name,age,fare,ticketType);
        System.out.println("Ticket booked! Passenger ID: "+id);
    }
    @Override
    public void cancelTicket(int id) throws IncorrectIdException{
        for(int i=0; i<passengerCount; i++){
            if(passengers[i].id == id){
                System.out.println("Ticket cancelled for "+passengers[i].name);
                for(int j=i; j<passengerCount-1; j++){
                    passengers[j] = passengers[j+1];
                }
                passengers[--passengerCount] = null;
                return;
            }
        }
        throw new IncorrectIdException();
    }
    @Override
    public void displayDetails(){
        System.out.println("~~~ EXPRESS TRAIN ~~~");
        System.out.println("Train No.: "+trainNumber+"| Train Type: "+trainType);
        System.out.println("Departure: "+departureTime+"| Source: "+source);
        System.out.println("Destination: "+destination);
        System.out.println("--- PASSENGER DETAILS ---");
        for(int i=0; i<passengerCount; i++){
            System.out.println("ID: "+passengers[i].id+" | Name: "+passengers[i].name+" | Age: "+passengers[i].age);
            System.out.println("Fare: Rs"+passengers[i].fare+" | Type: "+passengers[i].ticketType);
        }
    }
}
public class pyq1 {
    public static void main(String[] args){
        int ch = 0;
        Train[] trains = new Train[5];
        int trainCount = 0;
        Scanner sc = new Scanner(System.in); 
        while(ch!=5){
            System.out.println("~~~ MENU ~~~");
            System.out.println("1.Add Train");
            System.out.println("2.Book Ticket");
            System.out.println("3.Cancel Ticket");
            System.out.println("4.Display Details");
            System.out.println("5.Exit Menu");
            ch = sc.nextInt();
            switch(ch){ 
                case 1:
                        System.out.println("Train Type: 1.Local 2.Express");
                        int tt = sc.nextInt();
                        System.out.println("Train Number: ");
                        int tn = sc.nextInt();
                        sc.nextLine();
                        System.out.println("Departure Time: ");
                        String dt = sc.nextLine(); 
                        System.out.println("Source: ");
                        String src = sc.nextLine();
                        System.out.println("Destination: ");
                        String dest = sc.nextLine();
                        if(tt == 1){
                            trains[trainCount++] = new LocalTrain(tn, dt, src, dest);
                        } else {
                            trains[trainCount++] = new ExpressTrain(tn, dt, src, dest);
                        }
                        System.out.println("Train Added!");
                        break;
                case 2:
                        System.out.println("Enter Train Number: ");
                        int bookTn = sc.nextInt();
                        Train bookTrain = null;
                        for(int i=0; i<trainCount; i++){
                            if(trains[i].trainNumber == bookTn) bookTrain = trains[i];
                        }
                        if(bookTrain == null){ System.out.println("Train not found."); break; }
                        System.out.println("Passenger ID: ");
                        int pid = sc.nextInt();
                        sc.nextLine();
                        System.out.println("Name: ");
                        String pname = sc.nextLine();
                        System.out.println("Age: ");
                        int age = sc.nextInt();
                        System.out.println("Fare: ");
                        double fare = sc.nextDouble();
                        sc.nextLine();
                        System.out.println("Ticket Type: ");
                        String ttype = sc.nextLine();
                        ((TicketManage)bookTrain).bookTicket(pid, pname, age, fare, ttype);
                        break;
                case 3:
                        System.out.println("Enter Train Number: ");
                        int canTn = sc.nextInt();
                        Train canTrain = null;
                        for(int i=0; i<trainCount; i++){
                            if(trains[i].trainNumber == canTn) canTrain = trains[i];
                        }
                        if(canTrain == null){ System.out.println("Train not found."); break; }
                        System.out.println("Enter Passenger ID to cancel: ");
                        int cid = sc.nextInt();
                        try{
                            ((TicketManage)canTrain).cancelTicket(cid);
                        } catch(IncorrectIdException e){
                            System.out.println(e);
                        }
                        break;
                case 4:
                        System.out.println("Train Number (0 for all): ");
                        int dispTn = sc.nextInt();
                        for(int i=0; i<trainCount; i++){
                            if(dispTn == 0 || trains[i].trainNumber == dispTn)
                                ((TicketManage)trains[i]).displayDetails();
                        }
                        break;
                case 5:
                        System.out.println("Exiting menu....");
                        break; 
                default:
                        System.out.println("Invalid choice!");
            }
        }
        sc.close();
    }
}