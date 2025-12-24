#include <stdio.h>
int main(){
    int i,j,m,n,a[10][10],flag=0;
    printf("Rows and cols: ");
    scanf("%d%d",&m,&n);
    if(m!=n){
        printf("Not square matrix, so no symmtery!");
        return 0;
    }
    printf("Enter ele:\n");
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
        if(flag==-1)
            break;
    }
    if(flag==0){
        printf("Symmetric!");
    }
    else
        printf("Not symmetric!");
    return 0;
}