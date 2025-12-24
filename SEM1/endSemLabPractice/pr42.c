#include <stdio.h>
int main(){
    int n,original,d,sum=0;
    scanf("%d",&n);
    original = n;  // Store original value
    while(n!=0){
        d=n%10;
        int fact=1;
        for(int j=2;j<=d;j++){
            fact=fact*j;
        }
        sum+=fact;
        n=n/10;
    }
    if(original==sum){
        printf("Strong");
    }
    else
        printf("Not strong");
    return 0;
}