package SEM2.oops_lab.endsemfin;

class ItemNotAvailableException extends Exception {
    String title;
    ItemNotAvailableException(String t) {
        this.title = t;
    }
    @Override
    public String toString() {
        return title + " not available!";
    }
}

interface LibraryItem {
    String getTitle();
    String getType();
    void display();
}

interface Reservable {
    void reserve(String memberName) throws ItemNotAvailableException;
}

abstract class Item implements LibraryItem {
    private int itemId;
    private String title;
    private boolean availability;

    Item(int id, String t, boolean available) {
        this.itemId = id;
        this.title = t;
        this.availability = available;
    }

    @Override
    public String getTitle() { return title; }

    int getID() { return itemId; }

    public boolean getAvailability() { return availability; }

    public void setAvailability(boolean b) { this.availability = b; }

    @Override
    public void display() {
        System.out.println("ID: " + itemId + " | Title: " + title + " | Availability: " + availability);
    }
}

class Book extends Item implements Reservable {
    String author, subject;

    Book(int id, String t, boolean b, String auth, String sub) {
        super(id, t, b);
        this.author = auth;
        this.subject = sub;
    }

    @Override
    public String getType() { return "Book"; }

    @Override
    public void display() {
        super.display();
        System.out.println("Author: " + author + " | Subject: " + subject);
    }

    @Override
    public void reserve(String memberName) throws ItemNotAvailableException {
        if (!getAvailability())
            throw new ItemNotAvailableException(getTitle());
        setAvailability(false);
        System.out.println(getTitle() + " reserved by " + memberName);
    }
}

class Journal extends Item {
    String publisher;

    Journal(int id, String t, boolean b, String p) {
        super(id, t, b);
        this.publisher = p;
    }

    @Override
    public String getType() { return "Journal"; }

    @Override
    public void display() {
        super.display();
        System.out.println("Publisher: " + publisher);
    }
}

class Library {
    static Book[] books = new Book[10];
    static int count = 0;

    static {
        books[count++] = new Book(101, "Calculus", true, "James", "Math");
        books[count++] = new Book(102, "Planets", true, "Bob", "Physics");
        books[count++] = new Book(103, "Trigno world", false, "Amy", "Math");
        books[count++] = new Book(104, "Moral ethics", true, "Lingo", "General");
        books[count++] = new Book(105, "One dim world", false, "Rando", "Physics");
    }

    static void addItem(Book b) {
        if (count < 10) {
            books[count++] = b;
            System.out.println("Book added: " + b.getTitle());
        } else {
            System.out.println("Library full!");
        }
    }

    static Book searchbyTitle(String title) {
        for (int i = 0; i < count; i++) {
            if (books[i].getTitle().equalsIgnoreCase(title))
                return books[i];
        }
        return null;
    }
}

public class bigfin25 {
    public static void main(String[] args) {
        Library.addItem(new Book(106, "Computer Networks", true, "Tanenbaum", "CS"));

        Book found = Library.searchbyTitle("Trigno world");
        if (found != null) {
            try {
                found.reserve("Fattah");
            } catch (ItemNotAvailableException e) {
                System.out.println(e);
            }
        }

        System.out.println("\n--- All Books ---");
        LibraryItem[] items = Library.books;
        for (int i = 0; i < Library.count; i++) {
            if (items[i] != null)
                items[i].display();
        }
    }
}