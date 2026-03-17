#include <stdio.h>
int main(){
    int bd=0;
    long long n;
    long long a[3]={251580051696,251580051793,251580051534};
    scanf("%lld",&n);
    for(int i=0;i<3;i++){
        if(a[i]==n){
            bd=1;
            break;
        }
    }
    if(bd==0)
        printf("Eligible");
    else
        printf("Banned");
    return 0;
}