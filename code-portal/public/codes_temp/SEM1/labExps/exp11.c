#include <stdio.h>
#include <math.h>
int main(){
    float disc,r1,r2,r,real,imag,a,b,c;
    int choice;
    printf("Enter coefficients a,b and c: ");
    scanf("%f%f%f",&a,&b,&c);
    disc=(pow(b,2)-4*a*c);
    if(disc==0)
        choice=1;
    else if(disc>0)
        choice=2;
    else
        choice=3;
    switch(choice){
        case 1: printf("Equal and real roots...\n");
                r=-b/(2*a);
                printf("Root = %.2f",r);
                break;
        case 2: printf("Real and distinct roots...\n");
                r1=(-b+pow(disc,0.5))/(2*a);
                r2=(-b-pow(disc,0.5))/(2*a);
                printf("Root 1 = %.2f\n",r1);
                printf("Root 2 = %.2f\n",r2);
                break;
        case 3: printf("Imaginary roots...\n");
                real=-b/(2*a);
                imag=pow(fabs(disc),0.5)/(2*a);
                printf("Root 1 = %.2f + %.2fi\n",real,imag);
                printf("Root 2 = %.2f - %.2fi",real,imag);
                break;
        default :printf("Invalid!");
    }
    return 0;
}