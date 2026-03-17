//Compute trace and normal of given square matrix
#include <stdio.h>
#include <math.h>
int main(){
    int i,j,n,a[30][30],trace=0;
    double norm=0;
    printf("Enter dimension n for the square matrix (n x n): ");
    scanf("%d",&n);
    printf("Enter matrix elements\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j){
                trace+=a[i][j];
            }
            norm+=(double)a[i][j]*(double)a[i][j];
        }
    }
    norm=sqrt(norm);
    printf("Trace of matrix = %d\n",trace);
    printf("Norm of matrix = %.4f",norm);
    return 0;
}