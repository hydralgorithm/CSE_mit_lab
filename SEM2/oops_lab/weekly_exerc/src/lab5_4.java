class Weather{
    double temp, humidity;
    String city;
    
    Weather(String c, double t, double h){
        this.city = c;
        this.temp = t;
        this.humidity = h;
    }
    static class Forecast{
        static String predict(double t, double h){
            if(t>30 && h<50){
                return "Sunny";
            } else if( h>70){
                return "Rainy";
            } else {
                return "Cloudy";
            }
        }
        void display(Weather w){
            System.out.println("City: " + w.city);
            System.out.println("Temperature: " + w.temp + " Humidity: " + w.humidity);
            System.out.println("Weather: " + predict(w.temp, w.humidity));
            System.out.println();
        }
    }
}
public class lab5_4 {
    public static void main(String[] args){
        Weather w1 = new Weather("Kolkata", 35, 45);
        Weather w2 = new Weather("Mumbai", 29, 80);
        Weather w3 = new Weather("Bengaluru", 24, 60);

        Weather.Forecast f = new Weather.Forecast();
        f.display(w1);
        f.display(w2);
        f.display(w3);
    }
}
