#include <stdio.h>
#include <math.h>
int main(){
    float radius,area,volume;
    printf("Enter radius = ");
    scanf("%f",&radius);
    area = 4*3.14*pow(radius,2);
    volume=(4*3.14*pow(radius,3))/3;
    printf("Surface Area = %.2f\n",area);
    printf("Volume = %.2f",volume);
    return 0;
}