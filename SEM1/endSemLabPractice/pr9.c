#include <stdio.h>
#include <math.h>
int main(){
    float disc,a,b,c,r1,r2,r,real,imag;
    int choice;
    printf("Enter a,b,c: ");
    scanf("%f%f%f",&a,&b,&c);
    disc=(b*b)-(4*a*c);
    if(disc==0)
        choice=1;
    else if(disc>0){
        choice=2;
    }
    else
        choice=3;
    switch(choice){
        case 1: printf("Real and equal\n");
                r=(-b)/(2*a);
                printf("R=R1=R2= %.2f\n",r);
                break;
        case 2: printf("Distinct\n");
                r1=(-b+sqrt(disc))/(2*a);
                r2=(-b-sqrt(disc))/(2*a);
                printf("R1 = %.2f\nR2 = %.2f\n",r1,r2);
                break;
        case 3: printf("Imaginary roots\n");
                real=(-b)/(2*a);
                imag=pow(fabs(disc),0.5)/(2*a);
                printf("R1= %.2f + %.2fi\nR2= %.2f - %.2fi",real,imag,real,imag);
                break;
        default: printf("ERROR!");
    }
    return 0;
}