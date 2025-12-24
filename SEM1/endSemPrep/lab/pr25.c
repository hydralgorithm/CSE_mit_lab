#include <stdio.h>
#include <math.h>
int main(){
    int trace=0,a[10][10],i,j,n;
    double norm=0;
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
            norm+=pow((double)a[i][j],2);
        }
    }
    norm= sqrt(norm);
    printf("Trace = %d\nNorm = %.2f",trace,norm);
    return 0;
}