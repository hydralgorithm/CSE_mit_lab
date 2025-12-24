#include <stdio.h>
int main(){
    int d,n,ec=0,oc=0;
    scanf("%d",&n);
    while(n!=0){
        d=n%10;
        if(d%2==0){
            ec+=1;
        }else{
            oc+=1;
        }
        n=n/10;
    }
    printf("Odd = %d\nEven = %d",oc,ec);
    return 0;
}