#include <stdio.h>
int cornerSum(int a[10][10],int row,int col){
    int csum=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if((i==0||i==row-1) && (j==0 || j==col-1))
            csum+=a[i][j];
        }
    }
    return csum;        
}
int main(){
    int i,j,r,c,a[10][10];
    printf("Enter no of rows: ");
    scanf("%d",&r);
    printf("Enter number of columns: ");
    scanf("%d",&c);
    printf("Enter the matrix elements:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int corSum = cornerSum(a,r,c);
    printf("Sum of corners of a matrix = %d",corSum);
    return 0;
}