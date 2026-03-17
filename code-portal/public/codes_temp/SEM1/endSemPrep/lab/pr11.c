#include <stdio.h>
int main(){
    int small,c,a,b;
    scanf("%d%d%d",&a,&b,&c);
    small=(a<b)?a:b;
    small=(small<c)?small:c;
    printf("Smol : %d",small);
    return 0;
}