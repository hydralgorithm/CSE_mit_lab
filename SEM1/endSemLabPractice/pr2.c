#include <stdio.h>
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    printf("Sum=%d\n",a+b);
    printf("Difference = %d\n",a-b);
    printf("Product = %d\n",a*b);
    if(b==0){
        printf("Not possible\n");
    }
    else{
        printf("Quotient = %d\n",a/b);
    }
    return 0;
}