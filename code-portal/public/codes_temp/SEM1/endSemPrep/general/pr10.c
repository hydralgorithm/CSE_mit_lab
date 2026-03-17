#include <stdio.h>
int main(){
    int dsum,a[10][10],i,j,m,n,rsum[10],csum[10],flag=0;
    scanf("%d%d",&m,&n);
    if(m!=n){
        printf("Not magic square!");
        return 0;
    }
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
    for(i=0;i<m-1;i++){
        if(rsum[i]!=rsum[i+1]){
            printf("Not magic square!");
            return 0;
        }
    }
    for(j=0;j<n;j++){
        csum[j]=0;
        for(i=0;i<m;i++){
            csum[j]=csum[j]+a[i][j];
        }
    }
    for(j=0;j<n-1;j++){
        if(csum[j]!=csum[j+1]){
            printf("Not magic square!");
            return 0;
        }
    }
    // Check main diagonal
    dsum=0;
    for(i=0;i<m;i++){
        dsum+=a[i][i];
    }
    if(dsum!=rsum[0]){
        printf("Not magic square!");
        return 0;
    }
    
    // Check anti-diagonal
    int antidsum=0;
    for(i=0;i<m;i++){
        antidsum+=a[i][m-1-i];
    }
    if(antidsum!=rsum[0]){
        printf("Not magic square!");
        return 0;
    }


    printf("Yes it magic square!");
    return 0;
}