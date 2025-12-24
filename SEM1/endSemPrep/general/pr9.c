#include <stdio.h>
int main(){
    int a[10][10],rsum[10],csum[10],m,n,i,j;
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<m;i++){
        rsum[i]=0;
        for(j=0;j<n;j++){
            rsum[i]=rsum[i]+a[i][j];
        }          
    }
    for(j=0;j<n;j++){
        csum[j]=0;
        for(i=0;i<m;i++){
            csum[j]= csum[j]+a[i][j];
        }
    }
    printf("Matrix with row sums:\n");
    for(i=0;i<m;i++){  // Use m (rows) not n
        for(j=0;j<n;j++){
            printf("%d\t",a[i][j]);
        }
        printf("| %d\n",rsum[i]);  // Print row sum once per row
    }
    // Print separator
    for(j=0;j<n;j++){
        printf("---\t");
    }
    printf("\n");
    
    // Print column sums
    for(j=0;j<n;j++){
        printf("%d\t",csum[j]);
    }
    printf("\n");
    return 0;
}