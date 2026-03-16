import java.util.Scanner;

public class lab1_3better {
    static void reverseRange(int[] arr, int start, int end){
        while (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
    static void printArr(int[] arr){
        for(int i=0; i<arr.length; i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter array size: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter array elements: ");
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        System.out.print("Enter direction to rotate array towards(L or R): ");
        char dir = sc.next().trim().charAt(0);
        dir = Character.toUpperCase(dir);
        System.out.print("Enter number of steps to rotate array: ");
        int k = sc.nextInt();

        System.out.println("Original array: ");
        printArr(arr);
        
        if(dir == 'L'){
            k = k%arr.length;
            reverseRange(arr, 0, k - 1);
            reverseRange(arr, k, arr.length - 1);
            reverseRange(arr, 0, arr.length - 1);
            System.out.println("Rotated array: ");
            printArr(arr);
        } else if(dir == 'R'){
            k = (-1*k)%arr.length + arr.length;
            reverseRange(arr, 0, k - 1);
            reverseRange(arr, k, arr.length - 1);
            reverseRange(arr, 0, arr.length - 1);
            System.out.println("Rotated array: ");
            printArr(arr);
        } else{
            System.out.println("Invalid direction! Try again!");
            return;
        }
    }
}
