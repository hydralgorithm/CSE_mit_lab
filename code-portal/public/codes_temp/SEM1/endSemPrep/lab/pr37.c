#include <stdio.h>
int swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    swap(&a,&b);
    printf("a = %d\n",a);
    printf("b = %d",b);
    return 0;
}