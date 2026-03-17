import java.util.Scanner;

class Matrix{
    private int[][] arr;
    
    Matrix(int m, int n){
        this.arr = new int[m][n];
    }

    Matrix(int[][] a){
        int row = a.length;
        int col = a[0].length;
        this.arr = new int[row][col];
        for(int i=0; i< row;i++){
            for(int j=0; j< col; j++){
                this.arr[i][j] = a[i][j]; 
            }
        }
    }

    void display(){
        for(int row[] : arr){
            for(int num : row){
                System.out.print(num+" ");
            }
            System.out.println();
        }
    }



}

public class twoDArr {
    public static void main(String args[]){
        Scanner sc =new Scanner(System.in);
        Matrix m1 = new Matrix(2,3);
        int[][] arr = {{2,3,4},{3,4,1},{4,5,2}};
        Matrix m2 = new Matrix(arr);
        m1.display();
        m2.display();
        sc.close();
    }
}
