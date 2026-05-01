package SEM2.oops_lab.endsemfin;

class BookingException extends Exception {
    int code;
    String reason;

    BookingException(int code, String reason) {
        this.code = code;
        this.reason = reason;
    }

    @Override
    public String toString() {
        return "BookingException [code=" + code + "] : " + reason;
    }
}

class Ticket {
    private int ticketId, seatsAvailable;
    private String eventName;

    Ticket(String n, int seats) {
        this.eventName = n;
        this.seatsAvailable = seats;
    }

    void bookSeats(int requested) throws BookingException {
        if (requested <= 0)
            throw new BookingException(1, "Invalid seat count");
        if (requested > seatsAvailable)
            throw new BookingException(2, "Only " + seatsAvailable + " seats left");
        seatsAvailable -= requested;
        System.out.println(requested + " seats booked!");
    }

    void cancelSeats(int n) {
        seatsAvailable += n;
        System.out.println(n + " seats cancelled. Available: " + seatsAvailable);
    }
}

public class bigfin24 {
    public static void main(String[] args) {
        Ticket t = new Ticket("Techsolstice", 300);

        // scenario 1 - invalid seat count
        try {
            t.bookSeats(-2);
        } catch (BookingException e) {
            System.out.println(e);
        }

        // scenario 2 - not enough seats
        try {
            t.bookSeats(600);
        } catch (BookingException e) {
            System.out.println(e);
        }

        // scenario 3 - valid booking
        try {
            t.bookSeats(60);
        } catch (BookingException e) {
            System.out.println(e);
        }

        // cancelSeats demo
        t.cancelSeats(10);
    }
}