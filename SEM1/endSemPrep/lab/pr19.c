#include <stdio.h>
int main(){
    int n,sum=0;
    scanf("%d",&n);  // Fix 1: Add missing %
    
    for(int i=1;i<=n/2;i++){
        if(n%i==0){
            sum+=i;  // Fix 2: Add the divisor, not 1
        }    
    }
    if(n==sum)
        printf("Perfect!");
    else 
        printf("Not perfect!");
    return 0;
}