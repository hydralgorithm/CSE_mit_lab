class PaymentMethod{
    String paymentType;
    double amount;
    String details;

    PaymentMethod(){
        this.paymentType = "COD";
        this.amount = 0;
        this.details = "COD";
    }

    PaymentMethod(String cardType, double amount){
        this.paymentType = cardType+ " card";
        this.amount = amount;
        this.details = cardType + " card payment";
    }

    PaymentMethod(String id, double amount, boolean isUpi){
        if(isUpi){
            this.paymentType = "UPI";
            this.amount = amount;
            this.details = "UPI payment using ID: "+id; 
        }
    }
    public void processPayment(){
        if(paymentType.equals("COD")){
            System.out.println("COD COLLECTION!");
        }else {
            System.out.println("Processing "+details+" for rs."+amount);
        }
    }
}

public class billPayment {
    public static void main(String args[]){
        PaymentMethod bp1 = new PaymentMethod();
        bp1.processPayment();

        PaymentMethod bp2 = new PaymentMethod("Debit", 6570);
        bp2.processPayment();

        PaymentMethod bp3 = new PaymentMethod("Credit",79854);
        bp3.processPayment();

        PaymentMethod bp4 = new PaymentMethod("okay@upi",4500,true);
        bp4.processPayment();
    }
}
