#include <stdio.h>
int main(){
    int i,j,a[10][10],n,m,r1,r2,c1,c2;
    printf("Enter mat size: ");
    scanf("%d%d",&m,&n);
    printf("Ent matrix ele:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter rows to exchange: ");
    scanf("%d%d",&r1,&r2);
    printf("Enter cols to exchange: ");
    scanf("%d%d",&c1,&c2);
    for(j=0;j<n;j++){
        int temp= a[r1][j];
        a[r1][j]=a[r2][j];
        a[r2][j]=temp;
    }
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