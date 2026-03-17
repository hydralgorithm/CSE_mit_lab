#include <stdio.h>
int main(){
    int a,b,c,small;
    printf("Enter 3 numbers: ");
    scanf("%d%d%d",&a,&b,&c);
    small=(a<b)?a:b;
    small=(c<small)?c:small;
    printf("Smallest number is %d",small);
    return 0;
}