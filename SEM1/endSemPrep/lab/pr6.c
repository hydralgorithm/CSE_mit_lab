#include <stdio.h>
int main(){
    float v,r,sa;
    scanf("%f",&r);
    v=(4*3.14*r*r*r)/3;
    sa=4*3.14*r*r;
    printf("v=%.2f\nsa=%.2f",v,sa);
    return 0;
}