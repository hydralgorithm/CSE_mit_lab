#include <stdio.h>
#include <math.h>
int main(){
    int a[10][10],i,j,trace=0,n;
    double norm,prod=1;
    scanf("%d",&n);
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
            prod+=a[i][j]*a[i][j];
        }
    }
    norm=sqrt(prod);
    printf("Trace = %d\nNorm = %.2f",trace,norm);
    return 0;
}