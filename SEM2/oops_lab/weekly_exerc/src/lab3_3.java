import java.util.Scanner;

class Mixer{
    int[] arr;
    private static final Scanner sc = new Scanner(System.in);

    void accept(){
        System.out.print("Enter num of elements in array: ");
        int n = sc.nextInt();
        arr = new int[n];

        System.out.println("Enter " + n + " elements in ascending order (no duplicates):");
        for(int i=0; i<n; i++){
            int val = sc.nextInt();
            if(i > 0 && val <= arr[i - 1]){
                System.out.println("Invalid input. Enter a value greater than " + arr[i - 1]);
                i--;
            } else {
                arr[i] = val;
            }
        }

    }
    Mixer mix(Mixer A){
        Mixer result = new Mixer();

        int[] temp = new int[this.arr.length + A.arr.length];
        int i = 0;
        int j = 0;
        int k = 0;

        while(i < this.arr.length && j < A.arr.length){
            if(this.arr[i] < A.arr[j]){
                temp[k++] = this.arr[i++];
            } else if(this.arr[i] > A.arr[j]){
                temp[k++] = A.arr[j++];
            } else {
                temp[k++] = this.arr[i];
                i++;
                j++;
            }
        }

        while(i < this.arr.length){
            temp[k++] = this.arr[i++];
        }

        while(j < A.arr.length){
            temp[k++] = A.arr[j++];
        }

        result.arr = new int[k];
        for(int idx = 0; idx < k; idx++){
            result.arr[idx] = temp[idx];
        }

        return result;
    }
    void display(){
        for(int n : arr){
            System.out.print(n + " ");
        }
        System.out.println();
    }
}
public class lab3_3 {
    public static void main(String[] args){
        Mixer m1 = new Mixer();
        Mixer m2 = new Mixer();

        System.out.println("Enter first array details:");
        m1.accept();

        System.out.println("Enter second array details:");
        m2.accept();

        Mixer m3 = m1.mix(m2);

        System.out.println("First array:");
        m1.display();
        System.out.println("Second array:");
        m2.display();
        System.out.println("Merged array:");
        m3.display();
    }
}
