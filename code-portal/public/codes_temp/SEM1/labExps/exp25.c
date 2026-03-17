//Matrix symmetric or not
#include <stdio.h>
int main(){
    int i,j,a[30][30],m,n,flag=0;
    printf("Enter matrix dimension m x n: ");
    scanf("%d%d",&m,&n);
    if(m!=n){
        printf("Asymmetric matrix(not square matrix)");
        return 0;
    }
    printf("Enter matrix elements:\n");
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
        if(flag==-1) break;
    }
    if(flag==0){
        printf("Symmetric matrix!");
    }
    else
        printf("Asymmetric matrix!");
    return 0;
}