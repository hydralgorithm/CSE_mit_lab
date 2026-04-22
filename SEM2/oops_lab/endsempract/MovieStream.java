import java.util.Scanner;
import java.util.ArrayList;
class Movie{
    String title, genre;
    double rating;
    static int count = 0;
    Movie(String t, String g, double r){
        this.title = t;
        this.genre = g;
        this.rating = r;
        count++;
    }
    Movie(String t){
        this.title = t;
        this.genre = "Unknown";
        this.rating = 0.0;
    }
    void updateRating(double newRating){
        this.rating = newRating;
    }
    void display(){
        System.out.println("Title: "+title);
        System.out.println("Genre: "+genre);
        System.out.println("Rating: "+rating);
    }
    static void displayCount(){
        System.out.println("Total movies created: "+count);
    }
}
class Viewer{
    String name;
    ArrayList<Movie> watchedMovies = new ArrayList<>();
    Viewer(String n){
        this.name = n;
    } 
    void addMovie(Movie m){
        watchedMovies.add(m);
    }
    void display(){
        System.out.println("Viewer: "+name);
        System.out.println("Watched Movies: ");
        for(Movie m: watchedMovies){
            m.display();
            System.out.println();
        }
    }
}
public class MovieStream {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        Movie m1 = new Movie("Tarazan","Wildlife",6.7);
        m1.display();
        System.out.println();
        
        m1.updateRating(7.6);
        m1.display();
        System.out.println();

        Movie m2 = new Movie("Three Idiots");
        m2.display();
        Movie.displayCount();
        System.out.println();

        System.out.print("Enter num of movies: ");
        int n = sc.nextInt();
        sc.nextLine();
        ArrayList<Movie> movies= new ArrayList<>();
        for(int i=0; i<n; i++){
            System.out.print("Title: ");
            String t = sc.nextLine();
            System.out.print("Genre: ");
            String g = sc.nextLine();
            System.out.print("Rating: ");
            double r = sc.nextDouble();
            sc.nextLine();
            movies.add(new Movie(t, g, r));
            for (Movie m : movies) {
            m.display();
            System.out.println();
        }

        // (e) viewer profile
        System.out.println("--- (e) ---");
        Viewer v = new Viewer("Alex");
        v.addMovie(m1);
        v.addMovie(m2);
        v.display();

        sc.close();
        }
    }
}
