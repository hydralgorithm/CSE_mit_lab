import java.util.Scanner;

public class lab2_4 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter array size: ");
        int n = sc.nextInt();
        int[][] arr = new int[n][n];
        System.out.println("Enter array elements: ");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr[i][j] = sc.nextInt();
            }
        }
        sc.close();
        int sum = 0;
        System.out.println("Non-principal diagonal elements:");
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i + j != n - 1){
                    System.out.print(arr[i][j] + " ");
                    sum += arr[i][j];
                }
            }
        }
        System.out.println();
        System.out.println("Sum = " + sum);

    }
}
