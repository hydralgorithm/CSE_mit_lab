#include <stdio.h>
long long Fact(int n){
    long long facto=1;
    for(int i=2;i<=n;i++){
        facto*=i;
    }
    return facto;
}
int main(){
    int n,r;
    long long nfact,rfact,cfact;
    printf("Enter n and r for nCr: ");
    scanf("%d%d",&n,&r);
    if(r>n || r<0){
        printf("Invalid input!");
        return 0;
    }
    nfact = Fact(n);
    rfact = Fact(r);
    cfact = Fact(n-r);
    long long ncr = nfact/(cfact*rfact);
    printf("The value of %dC%d is: %lld",n,r,ncr); 
    return 0;
}