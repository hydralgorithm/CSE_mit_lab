#include <stdio.h>
void swap(int *x,int *y){
    int temp=*x;
        *x=*y;
        *y=temp;
}
int main(){
    int n1,n2;
    printf("Enter num1 and num2: ");
    scanf("%d%d",&n1,&n2);
    printf("Before swapping:\nnum1=%d and num2=%d\n",n1,n2);
    swap(&n1,&n2);
    printf("After swapping:\nnum1=%d and num2=%d",n1,n2);
    return 0;
}