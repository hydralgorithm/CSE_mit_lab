#include <stdio.h>
int main(){
    int a[10][10],i,j,m,n,flag=0;
    scanf("%d%d",&m,&n);
    if(m!=n){
        printf("Not symmetric!");
        return 0;
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(a[i][j]!=a[j][i]){
                flag=-1;
                break;
            }
        }
    }
    if(flag==0)
        printf("Symmetric!");
    else
        printf("Asymmetric!");
    return 0;
}