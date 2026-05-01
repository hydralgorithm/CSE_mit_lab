package SEM2.oops_lab.endsemfin.myPackages.p1;

public class Max{
    public int max(int n1, int n2, int n3){
        int maximum;
        if(n1>=n2 && n1>=n3)
            maximum = n1;
        else if(n2>=n1 && n2>=n3){
            maximum = n2;
        } else{
            maximum = n3;
        }
        return maximum;
    }
    public double max(double n1, double n2, double n3){
        double maximum;
        if(n1>=n2 && n1>=n3)
            maximum = n1;
        else if(n2>=n1 && n2>=n3){
            maximum = n2;
        } else{
            maximum = n3;
        }
        return maximum;
    }
}

