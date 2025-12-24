#include <stdio.h>
#include <math.h>
int main(){
    float P,N,R,SI,CI;
    printf("Enter inital Principal, Time in years and Interest rate:\n");
    scanf("%f%f%f",&P,&N,&R);
    SI=(P*N*R)/100;
    CI=P*pow(1+R/100,N)-P;
    printf("SI=%.2f   CI=%.2f",SI,CI);
    return 0;
}