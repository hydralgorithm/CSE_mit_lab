package SEM2.oops_lab.endsemfin;

interface Payable{
    double getPaymentAmount();
}
interface Taxable{
    double computeTax();
}
class Contractor implements Payable, Taxable{
    String name;
    double contractAmount;
    double taxRate;
    Contractor(String n, double cAmt, double taxRate){
        this.name = n;
        this.contractAmount = cAmt;
        this.taxRate = taxRate;
    }
    @Override
    public double getPaymentAmount(){
        return contractAmount-computeTax();
    }
    @Override
    public double computeTax(){
        return (taxRate/100)*contractAmount;
    }
}
class Product implements Payable{
    String productName;
    double price;
    Product(String n, double p){
        this.productName = n;
        this.price = p;
    }
    @Override
    public double getPaymentAmount(){
        return price;
    }
}
public class bigfin22 {
    public static void main(String[] args){
        Payable[] payables = {
            new Contractor("John Doe", 42000, 8.7),
            new Product("Pencil", 45)
        };
        for(int i=0; i<payables.length; i++){
            System.out.println("Payment amount: "+payables[i].getPaymentAmount());
        }
        Contractor c = new Contractor("Bendover", 12000, 6.7);
        System.out.println("Tax amount: "+c.computeTax());
    }
}
