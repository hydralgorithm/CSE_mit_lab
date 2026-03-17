#include <stdio.h>
#include <math.h>
int main(){
    float P,N,R,SI,CI;
    printf("Enter intial principle balance: ");
    scanf("%f",&P);
    printf("Enter time (in years): ");
    scanf("%f",&N);
    printf("Enter interest rate: ");
    scanf("%f",&R);
    SI = (P*N*R)/100;
    CI = P*pow(1+(R/100),N)-P;
    printf("Simple Interest = %.2f\n",SI);
    printf("Compound Interest = %.2f",CI);
    return 0;
}