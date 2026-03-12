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
            System.arraycopy(a[i],0,arr[i],0);
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

}
