package SEM2.oops_lab.endsemfin.Allpackage.Mypackage;

public class Macbook_air extends Macbook implements Browsing{
    public Macbook_air(int ram, String p){
        super(ram, p);    
    }
    @Override
    public void AccessInternet(String bandwidth){
        System.out.println("Accessing internet with: "+bandwidth);
    }
}
