import java.util.Scanner;

public class lesson1_3 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.printf("Enter array size: ");
        int n = sc.nextInt();

        int[] arr = new int[n];
        System.out.printf("\nEnter %d elements:\n",n);
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }

        System.out.print("Original array: ");
        printArray(arr);

        System.out.print("Enter direction to rotate (L or R): ");
        char direction = sc.next().charAt(0);

        System.out.print("Enter number of steps: ");
        int steps = sc.nextInt();

        steps = steps % n;

        if (direction == 'L' || direction == 'l') {
            rotateLeft(arr, steps);
        } else if (direction == 'R' || direction == 'r') {
            rotateRight(arr, steps);
        } else {
            System.out.println("Invalid direction!");
            return;
        }

        System.out.print("Rotated array: ");
        printArray(arr);

        sc.close();
    }

    static void printArray(int[] arr) {
        System.out.print("[");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
            if (i < arr.length - 1) {
                System.out.print(", ");
            }
        }
        System.out.println("]");
    }

    static void rotateRight(int[] arr, int steps) {
        int n = arr.length;
        if (steps == 0 || n == 0) return;

        int[] temp = new int[steps];
        for (int i = 0; i < steps; i++) {
            temp[i] = arr[n - steps + i];
        }

        for (int i = n - 1; i >= steps; i--) {
            arr[i] = arr[i - steps];
        }

        for (int i = 0; i < steps; i++) {
            arr[i] = temp[i];
        }
    }

    static void rotateLeft(int[] arr, int steps) {
        int n = arr.length;
        if (steps == 0 || n == 0) return;

        int[] temp = new int[steps];
        for (int i = 0; i < steps; i++) {
            temp[i] = arr[i];
        }

        for (int i = 0; i < n - steps; i++) {
            arr[i] = arr[i + steps];
        }

        for (int i = 0; i < steps; i++) {
            arr[n - steps + i] = temp[i];
        }
    }
}
