#include <stdio.h>
#include <math.h>
int main(){
    float a,b,c,r1,r2,r,real,imag,disc;
    int ch;
    printf("Enter a,b,c: " );
    scanf("%f%f%f",&a,&b,&c);
    disc = (b*b) -(4*a*c); 
    if(disc>0)
        ch=1;
    else if(disc==0)
        ch=2;
    else
        ch=3;
    switch(ch){
        case 1: printf("Real and distinct roots!\n");
                r1=(-b + sqrt(disc))/(2*a);
                r2=(-b - sqrt(disc))/(2*a);
                printf("R1 = %.2f\nR2 = %.2f",r1,r2);
                break;
        case 2: printf("Real and equal roots!\n");
                r=(-b)/(2*a);
                printf("R=R1=R2= %.2f",r);
                break;
        case 3: printf("Imaginary roots!\n");
                real=(-b)/(2*a);
                imag=(pow(fabs(disc),0.5))/(2*a);
                printf("R1 = %.2f + %.2fi\nR2 = %.2f - %.2fi",real,imag,real,imag);
                break;
        default : printf("Error!");
    }
    return 0;
}