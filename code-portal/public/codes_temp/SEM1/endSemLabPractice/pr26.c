#include <stdio.h>
int main(){
    int i,j,m,n,k,r,t;
    float a[10][10],b[10][10],c[10][10];
    scanf("%d%d%d%d",&m,&n,&k,&r);
    if(n!=k){
        printf("Incompatible!");
        return 0;
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%f",&a[i][j]);
        }
    }
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
    printf("Resultant matrix:\n");
    for(i=0;i<m;i++){
        for(j=0;j<r;j++){
            printf("%.2f ",c[i][j]);
        }
        printf("\n");
    }
    return 0;
}