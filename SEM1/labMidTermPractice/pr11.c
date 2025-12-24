#include <stdio.h>
#include <math.h>
int main(){
    float disc,a,b,c,r,r1,r2,real,imag;
    int choice;
    scanf("%f%f%f",&a,&b,&c);
    disc=b*b-4*a*c;
    if(disc>0)
        choice=1;
    else if(disc<0)
        choice=2;
    else
        choice=3;
    switch(choice){
        case 1: r1=(-b+sqrt(disc))/(2*a);
                r2=(-b-sqrt(disc))/(2*a);
                printf("r1=%.2f\tr2=%.2f",r1,r2);
                break;
        case 2: real=(-b)/(2*a);
                imag=pow(fabs(disc),0.5)/(2*a);
                printf("r1 = %.2f + %.2fi\nr2 = %.2f - %.2f",real,imag,real,imag);
                break;
        case 3: r=(-b)/(2*a);
                printf("r=%.2f",r);
                break;
        default: printf("ERROR");    
    }
    return 0;
}