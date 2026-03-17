#include <stdio.h>
int main(){
    int lar,a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(a>=b && a>=c)
        lar=a;
    else if(b>=a && b>=c)
        lar=b;
    else
        lar=c;
    printf("%d",lar);
    return 0;
}