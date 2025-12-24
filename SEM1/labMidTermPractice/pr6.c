#include <stdio.h>
int main(){
    float r,a,v;
    scanf("%f",&r);
    a=4*3.14*r*r;
    v=(4*3.14*r*r*r)/3;
    printf("Vol=%.2f Area=%.2f",v,a);
    return 0;
}