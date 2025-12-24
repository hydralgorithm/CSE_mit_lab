#include <stdio.h>
int main(){
    int a=30,b=10,c=5,d=15;
    int p,q,r,s;
    p=(a+b)*c/d;
    q=((a+b)*c)/d;
    r=a+(b*c)/d;
    s=(a+b)*(c/d);
    printf("The answer for (i) is %d\n",p);
    printf("The answer for (ii) is %d\n",q);
    printf("The answer for (iii) is %d\n",r);
    printf("The answer for (iv) is %d\n",s);
    return 0;
}