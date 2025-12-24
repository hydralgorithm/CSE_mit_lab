#include <stdio.h>
#include <math.h>
int main(){
    int n,p=0,k,d=0;
    scanf("%d",&n);
    do{
        k=n%10;
        d=d+(k*pow(2,p));
        p+=1;
        n=n/10;
    }while(n!=0);
    printf("Decimal number = %d",d);
    return 0;
}