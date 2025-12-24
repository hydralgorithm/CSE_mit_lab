#include <stdio.h>
int main(){
    int n,sum=0,d;
    scanf("%d",&n);
    int temp = n; 
    while(n!=0){
        d=n%10;
        sum = sum + (d*d*d);
        n=n/10;
    }
    if(temp==sum)
        printf("Armstrong number!");
    else
        printf("Not armstrong number!");
    return 0;
}