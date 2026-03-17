#include <stdio.h>

int cornerSum(int a[10][10],int r,int c){
    int csum = 0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if((i==0 || i==r-1) && (j==0 || j==c-1)){
                csum+=a[i][j];
            }
        }
    }
    return csum;
}
int main(){
    int a[10][10],i,j,m,n;
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int sum = cornerSum(a,m,n);
    printf("Sum = %d",sum);
    return 0;
}