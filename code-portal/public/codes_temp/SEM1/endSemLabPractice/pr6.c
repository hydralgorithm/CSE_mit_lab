#include <stdio.h>
int main(){
    float r,v,a;
    scanf("%f",&r);
    v=(4*3.14*r*r*r)/3;
    a=(4*3.14*r*r);
    printf("v=%.2f",v);
    printf("a=%.2f",a);
}