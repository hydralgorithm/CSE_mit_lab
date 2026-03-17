#include<stdio.h>
int main(){
    int n,sum=0,d,temp;
    scanf("%d",&n);
    temp=n;
    while(n!=0){
        d=n%10;
        sum=sum+(d*d*d);
        n=n/10;
    }
    if(temp==sum)
        printf("Armstrong");
    else
        printf("Not armstrong");
    return 0;
}