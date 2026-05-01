package SEM2.oops_lab.endsemfin;

class Book{
    private int book_id;
    private String title, author;
    private boolean availability;
    Book(int id, String title, String author){
        this.book_id = id;
        this.title = title;
        this.author = author;
        this.availability = true;
    }
    void display(){
        System.out.println("Book ID: "+book_id+" | Title: "+title);
        System.out.println("Author: "+author+"Availability: "+availability);
    }
}
class Textbook extends Book{
    String subject;
    Textbook(int id, String title, String author, String sub){
        super(id, title, author);
        this.subject = sub;
    }
    @Override
    void display(){
        System.out.println("Subject: "+subject);
        super.display();
    }


}
class Novel extends Book{
    String genre;
    Novel(int id, String title, String author, String genre){
        super(id, title, author);
        this.genre = genre;
    }
    @Override
    void display(){
        System.out.println("Subject: "+genre);
        super.display();
    }
}
class Library{
    static final int MAX_BOOKS = 5;
    static Book[] books = new Book[MAX_BOOKS];
    static int book_count=0;
    static{
        books[book_count++] = new Novel(101, "Sky High", "Jerremy","Action");
        books[book_count++] = new Novel(102, "Lolol", "pam","Romance");
        books[book_count++] = new Novel(103, "Harry Mate", "ram","Horror");
        books[book_count++] = new Textbook(104, "Addition ", "tam","Math");
        books[book_count++] = new Textbook(105, "Calculus", "cam","Physics");
    }
    static void addBook(Book book){
        if(book_count<MAX_BOOKS){
            books[book_count++] = book;
        }else{
            System.out.println("Max limit reached! cannot add books!");
        }
    }
    public static Book[] getAllBooks(){
        return books;
    }
}
public class fin11 {
    public static void main(String[] args){
        Library.addBook(new Novel(106, "Big man", "lil foot", "jolly"));
        Book[] books = Library.getAllBooks();
        System.out.println("Book info:");
        for(int i=0; i<books.length; i++){
            books[i].display();
        }
    }
}
