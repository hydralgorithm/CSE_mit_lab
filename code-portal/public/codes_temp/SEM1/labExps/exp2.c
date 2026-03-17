#include <stdio.h>
int main(){
    float num1,num2;
    printf("Enter 2 numbers :\n");
    scanf("%f%f",&num1,&num2);
    printf("Sum = %.2f\n",num1+num2);
    printf("Difference = %.2f\n",num1-num2);
    printf("Product = %.2f\n",num1*num2);
    if(num2!=0){
        printf("Quotient = %.2f\n",num1/num2);
    }
    else{
        printf("Not divisible!\n");
    }
    return 0;
}