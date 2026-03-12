import java.util.Scanner;

class Product {
    String name;
    int id, quant;

    Product(String n, int i, int q) {
        this.name = n;
        this.id = i;
        this.quant = q;
    }

    void display() {
        System.out.println("Name: " + name + ", ID: " + id + ", Quantity: " + quant);
    }
}

public class prodInv {
    static Product[] products;
    static int productCount = 0;

    // Method 1: Add a product
    static void addProduct(String n, int id, int q) {
        if (productCount < products.length) {
            products[productCount++] = new Product(n, id, q);
            System.out.println("Product added successfully!");
        } else {
            System.out.println("Inventory is full!");
        }
    }

    // Method 2: Display all products
    static void displayAllProducts() {
        if (productCount == 0) {
            System.out.println("No products in inventory.");
            return;
        }
        System.out.println("\n--- All Products ---");
        for (int i = 0; i < productCount; i++) {
            products[i].display();
        }
    }

    // Method 3: Find product by ID
    static void findProductById(int id) {
        for (int i = 0; i < productCount; i++) {
            if (products[i].id == id) {
                System.out.println("\nProduct found:");
                products[i].display();
                return;
            }
        }
        System.out.println("Product with ID " + id + " not found.");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter max number of products: ");
        int size = sc.nextInt();
        products = new Product[size];

        int choice;
        do {
            System.out.println("\n1. Add Product");
            System.out.println("2. Display All Products");
            System.out.println("3. Find Product by ID");
            System.out.println("4. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {
                case 1:
                    System.out.print("Name: ");
                    String n = sc.nextLine();
                    System.out.print("ID: ");
                    int id = sc.nextInt();
                    System.out.print("Quantity: ");
                    int q = sc.nextInt();
                    addProduct(n, id, q);
                    break;
                case 2:
                    displayAllProducts();
                    break;
                case 3:
                    System.out.print("Enter ID to search: ");
                    int searchId = sc.nextInt();
                    findProductById(searchId);
                    break;
                case 4:
                    System.out.println("Goodbye!");
                    break;
                default:
                    System.out.println("Invalid choice.");
            }
        } while (choice != 4);

        sc.close();
    }
}