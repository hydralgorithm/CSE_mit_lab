package SEM2.oops_lab.endsemfin;
import java.util.Scanner;

class ScreeningException extends Exception{
    int id1, id2;
    ScreeningException(int id1, int id2){
        this.id1 = id1;
        this.id2 = id2;
    }
    public String toString(){
        return "Schedules of movies with Ids"+id1+"and"+id2+"are conflicting";
    }
}

class Movie{
    short mov_id, screen_num;
    String pdate;
    float ptime;
    Movie(short id, short num, String date, float time){
        this.mov_id = id;
        this.screen_num = num;
        this.pdate = date;
        this.ptime = time;
    }
    void display(){
        System.out.println("Movie id: "+mov_id+" | Screen Num: "+screen_num);
        System.out.println("Date: "+pdate+" | Time: "+ptime);
    }
    void checkSchedule(Movie[] m) throws ScreeningException{
        for(int i=0; i<m.length-1; i++){
            for(int j=i+1; j<m.length; j++){
                if((m[i].pdate.equals(m[j].pdate)) && (m[i].screen_num == m[j].screen_num) &&
                    (Math.abs(m[i].ptime-m[j].ptime)<3)){
                        throw new ScreeningException(m[i].mov_id,m[j].mov_id);
                } 
            }
        }
    }
}

public class fin9 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Movie[] movies = new Movie[3];
        for(int i=0; i< movies.length; i++){
            System.out.print("Screen num: ");
            short screenNum = sc.nextShort();
            System.out.print("Movie id: ");
            short movid = sc.nextShort();
            System.out.print("Screen time: ");
            float time = sc.nextFloat();
            sc.nextLine();
            System.out.print("Date: ");
            String d = sc.nextLine();
            movies[i] = new Movie(movid, screenNum, d, time);
        }
        for(Movie m: movies){
            m.display();
        }
        try{
            for(int i=0; i<movies.length; i++){
                movies[i].checkSchedule(movies);
            }
        } catch(ScreeningException e){
            System.out.println(e);
        } finally{
            System.out.println("Program ended!");
        }
        sc.close();
    }
}
