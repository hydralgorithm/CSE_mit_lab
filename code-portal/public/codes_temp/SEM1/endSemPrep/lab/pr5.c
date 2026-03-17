#include <stdio.h>
#include <math.h>
int main(){
    float P,N,R;
    scanf("%f%f%f",&P,&N,&R);
    float SI = (P*N*R)/100; 
    float CI = P*(pow(1+(R/100),N))-P;
    printf("SI = %.2f\nCI = %.2f",SI,CI);
    return 0;
}