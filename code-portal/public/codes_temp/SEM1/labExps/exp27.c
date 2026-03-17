//Matrix multiplication
#include <stdio.h>
int main(){
    int i,j,m,n,k,r,t;
    float a[30][30],b[30][30],c[30][30];
    printf("Enter the dimensions of matrix 1: ");
    scanf("%d%d",&m,&n);
    printf("Enter the dimensions of matrix 2: ");
    scanf("%d%d",&k,&r);
    if(n!=k){
        printf("Incompatible dimensions!");
        return 0;
    }
    printf("Enter elements of matrix 1:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%f",&a[i][j]);
        }
    }
    printf("Enter elements of matrix 2:\n");
    for(i=0;i<k;i++){
        for(j=0;j<r;j++){
            scanf("%f",&b[i][j]);
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<r;j++){
            c[i][j]=0.0f;
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<r;j++){
            for(t=0;t<n;t++){
                c[i][j]+=a[i][t]*b[t][j];
            }
        }
    }
    printf("Resultant matrix (%d x %d):\n",m,r);
    for(i=0;i<m;i++){
        for(j=0;j<r;j++){
            printf("%.2f  ",c[i][j]);
        }
        printf("\n");
    }
    return 0;
}