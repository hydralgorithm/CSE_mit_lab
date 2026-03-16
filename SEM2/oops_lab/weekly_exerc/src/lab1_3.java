import java.util.Scanner;

public class lab1_3 {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the array size: ");
        int n = sc.nextInt();
        if (n <= 0) {
            System.out.println("Array size must be positive.");
            return;
        }
        int[] arr = new int[n];
        
        System.out.println("Enter "+n+" array elements: ");
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        System.out.println("Original array:");
        arrayPrint(arr);
        System.out.println();

        System.out.print("Enter direction to rotate array towards (L-1 or R-2): ");
        int choice = sc.nextInt();
        System.out.print("Enter number of steps to rotate: ");
        int k = sc.nextInt();
        sc.close();
        if(choice == 1){
            k = k % arr.length;
            arrRotate(arr, k);
            arrayPrint(arr);

        } else if (choice == 2){
            k = (-1*k)%arr.length + arr.length;
            arrRotate(arr, k);
            arrayPrint(arr);
        } else{
            System.out.println("Invalid direction!");
            return;
        }
    }
    
    static void arrayPrint(int[] arr){
        for(int i=0; i<arr.length ;i++){
            System.out.print(arr[i]+" ");
        }
    }

    static void rotateOne(int[] arr){
        int temp = arr[0];
        for(int i=1; i<arr.length; i++){
            arr[i-1] = arr[i];
        }
        arr[arr.length - 1] = temp;
    }

    static void arrRotate(int[] arr, int k){
        for(int i=1; i<=k; i++){
            rotateOne(arr);
        }
    }

}
