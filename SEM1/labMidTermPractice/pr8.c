#include <stdio.h>
int main(){
    int a=30,b=10,c=5,d=15;
    int p,q,r,s;
    p=(a+b)*c/d;
    q=((a+b)*c)/d;
    r=a+(b*c)/d;
    s=(a+b)*(c/d);
    printf("%d\t%d\t%d\t%d",p,q,r,s);
    return 0;
}