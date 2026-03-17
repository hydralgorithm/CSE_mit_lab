#include <stdio.h>
int main(){
    int n,k,i,j;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++){
        for(j=1;j<=k;j++){
            printf("%d  ",i*j);
        }
        printf("\n");
    }
    return 0;
}