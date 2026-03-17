#include <stdio.h>
int main(){
    float fahrenheit,centigrade;
    printf("Enter temperature in fahrenheit: ");
    scanf("%F",&fahrenheit);
    centigrade = (5*(fahrenheit-32))/9;
    printf("Centigrade = %.2f",centigrade);
    return 0;
}