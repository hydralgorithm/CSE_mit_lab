#include <stdio.h>
int main(){
    int n,i,j,geek=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            geek+=1;
            printf("%d  ",geek);
        }
        printf("\n");
    }
    return 0;
}