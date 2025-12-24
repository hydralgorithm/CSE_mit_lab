#include <stdio.h>
#include <math.h>
int main(){
    int x,n,i,j,sym;
    double sum=0.0,fact=1.0;
    scanf("%d%d",&x,&n);
    for(i=0;i<n;i++){
        int power = 2*i+1;
        if(i%2!=0)
            sym=-1;
        else
            sym=1;
        fact=1.0;
        for(j=1;j<=power;j++){
            fact= fact*j;
        }
        sum= sum + (sym*pow((double)x,power))/(fact);
    }
    printf("f(%d) = %.3f",x,sum);
    return 0;
}