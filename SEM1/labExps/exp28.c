// Interchange 2 rows and columns and display result matrix
#include <stdio.h>
int main(){
    int i,j,m,n,a[30][30],r1,r2,c1,c2;
    printf("Enter matrix dimensions: ");
    scanf("%d%d",&m,&n);
    printf("Enter matrix elements:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter two row indices to interchange(0 to %d): ",m-1);
    scanf("%d%d",&r1,&r2);
    for(j=0;j<n;j++){
        int temp = a[r1][j];
        a[r1][j] = a[r2][j];
        a[r2][j] = temp;
    }
    printf("Enter two column indices to interchange(0 to %d): ",n-1);
    scanf("%d%d",&c1,&c2);
    for(i=0;i<m;i++){
        int temp = a[i][c1];
        a[i][c1] = a[i][c2];
        a[i][c2] = temp;
    }
    
    printf("Resultant matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}