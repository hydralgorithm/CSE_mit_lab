#include <stdio.h>
int main(){
    int a[10][10],i,j,m,n,r1,r2,c1,c2;
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);  // Removed trailing space
        }
    }
    printf("row exch(0 to %d): ",m-1);
    scanf("%d%d",&r1,&r2);
    for(j=0;j<n;j++){
        int temp=a[r1][j];
        a[r1][j]=a[r2][j];
        a[r2][j]=temp;
    }
    printf("Col exch(0 to %d): ",n-1);
    scanf("%d%d",&c1,&c2);
    for(i=0;i<m;i++){
        int temp=a[i][c1];
        a[i][c1]=a[i][c2];
        a[i][c2]=temp;
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}