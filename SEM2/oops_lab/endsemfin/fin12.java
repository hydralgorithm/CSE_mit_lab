package SEM2.oops_lab.endsemfin;
class Matrix{
    int[][] arr;
    int row,col;
    Matrix(int n, int m){
        this.row = n;
        this.col = m;
        this.arr = new int[row][col]; 
    }
    Matrix(int[][] arr){
        this.row = arr.length;
        this.col = arr[0].length;
        this.arr = new int[row][col];
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                this.arr[i][j] = arr[i][j];
            }
        }
    }
    void displayMatrix(){
        for(int[] r : arr){
            for(int e: r){
                System.out.print(e+" ");
            }
            System.out.println();
        }
    }
    int[] find(){
        int[] palprime = new int[row*col];
        int count = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                int temp = arr[i][j];
                int prime = 1;
                if(temp<2)
                    continue;
                for(int k=2; k<temp/2; k++){
                    if(temp%k == 0){
                        prime = 0;
                        break;
                    }
                }
                int d=0, rev=0;
                temp = arr[i][j];
                while(temp!=0){
                    d = temp%10;
                    rev = rev*10 + d;
                    temp /= 10;
                }
                if(prime == 1 && rev == arr[i][j]){
                    palprime[count++] = arr[i][j];
                }
            }
        }
        return palprime; 
    }
}
public class fin12 {
    public static void main(String[] args){
        Matrix m1 = new Matrix(3,3);
        m1.displayMatrix();
        int[][] arr1 = {{121,223,131},
                        {101,253,747}};
        Matrix m2 = new Matrix(arr1);
        m2.displayMatrix();
        int[] tryarr = m2.find();
        for(int a: tryarr){
            if(a!=0)
                System.out.print(a+" ");
        }
    }
}
