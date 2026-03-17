#include <stdio.h>
int GCD(int a,int b){
    if(b==0)
        return a;
    else
        return GCD(b,a%b);
}
int main(){
    int a,b,gcd;
    scanf("%d%d",&a,&b);
    gcd = GCD(a,b);
    printf("GCD = %d",gcd);
}