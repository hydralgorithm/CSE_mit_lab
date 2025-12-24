#include <stdio.h>
long long Fact(int n){
    long long fac=1;
    for(int i=2;i<=n;i++){
        fac=fac*i;
    }
    return fac;
}
int main(){
    int n,r;
    printf("Enter n and r: ");
    scanf("%d%d",&n,&r);
    long long n_fact = Fact(n);
    long long r_fact = Fact(r);
    long long n_r_fact = Fact(n-r);
    long ncr = (n_fact)/(r_fact*n_r_fact);
    printf("%dC%d = %lld",n,r,ncr);
    return 0;
}