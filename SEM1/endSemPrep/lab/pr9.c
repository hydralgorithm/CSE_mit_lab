#include <stdio.h>
int main(){
    int a,b,c,lar;
    scanf("%d%d%d",&a,&b,&c);
    if(a>=b && a>=c)
        lar=a;
    else if(b>=a && b>=c)
        lar =b;
    else
        lar = c;
    printf("Largest = %d",lar); 
    return 0;
}