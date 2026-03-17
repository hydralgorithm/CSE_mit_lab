#include <stdio.h>
int main(){
    int d,sum=0,n;
    scanf("%d",&n);
    int temp=n;
    while(n!=0){
        d=n%10;
        sum=sum+(d*d*d);
        n=n/10;
    }
    if(temp==sum)
        printf("Arm");
    else
        printf("no arm");
        return 0;
}