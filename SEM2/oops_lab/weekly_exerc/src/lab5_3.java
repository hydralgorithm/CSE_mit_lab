class shoppingCart{
    double totalPrice;
    Item[] items;
    shoppingCart(int count){
        totalPrice = 0;
        items = new Item[count];
    }
    void addItem(int idx, String iname, int qty, double cost){
        if(idx < 0 || idx > items.length-1){
            System.out.println("Invalid index! Item cant be added!");
        } else{
            items[idx] = new Item(iname,qty,cost);
        }
    }
    void compute(){
        totalPrice = 0;
        for(Item i : items){
            if(i != null){
                totalPrice = totalPrice + (i.price * i.qunatity);
            }
        }
    }
    void displayDetails(){
        compute();
        System.out.println("------CART BILL------");
        for(Item i : items){
            if(i != null){
                System.out.println("Item Name: " + i.itemName + " | Price: " + i.price + " | Quantity: " + i.qunatity);
            }
        }
        System.out.println();
        System.out.println("Total Bill = Rs"+totalPrice);
    }
    class Item{
        String itemName;
        int qunatity;
        double price;
        Item(String n, int q, double p){
            this.itemName = n;
            this.qunatity = q;
            this.price = p;
        }
    }
}
public class lab5_3 {
    public static void main(String[] args){
        shoppingCart sc = new shoppingCart(3);
        sc.addItem(0, "apple", 5, 10.5);
        sc.addItem(1, "banana", 10, 5);
        sc.addItem(2, "Pen", 3, 50);
        sc.displayDetails();
    }
}
