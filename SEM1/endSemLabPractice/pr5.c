#include <stdio.h>
#include <math.h>
int main(){
    float SI,CI,p,r,n;
    scanf("%f%f%f",&p,&r,&n);
    SI=(p*n*r)/(100);
    printf("SI=%.2f\n",SI);
    CI=p*pow(1+(r/100),n)-p;
    printf("CI=%.2f",CI);
    return 0;
}