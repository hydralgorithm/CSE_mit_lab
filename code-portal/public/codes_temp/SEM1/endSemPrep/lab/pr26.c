#include <stdio.h>
int main(){
    float a[10][10],b[10][10],c[10][10];
    int i,j,m,n,k,r,t;
    printf("Enter array 1 dimensions: ");
    scanf("%d%d",&m,&n);
    printf("Enter array 2 dimensions: ");
    scanf("%d%d",&k,&r);
    if(n!=k){
        printf("Invalid dimension, multiplication not possible!");
        return 0;
    }
    printf("Enter array 1 ele:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%f",&a[i][j]);
        }
    }
    printf("Enter array 2 ele:\n");
    for(i=0;i<k;i++){
        for(j=0;j<r;j++){
            scanf("%f",&b[i][j]);  // Fix: Read into array b
        }
    }
    //Initailization
    for(i=0;i<m;i++){
        for(j=0;j<r;j++){
            c[i][j]=0.0;
        }
    }
    // Resultant
    for(i=0;i<m;i++){
        for(j=0;j<r;j++){
            for(t=0;t<n;t++){
                c[i][j]+=a[i][t]*b[t][j];
            }
        }
    }
    printf("Resultant Matrix:\n");
    for(i=0;i<m;i++){
        for(j=0;j<r;j++){
            printf("%.2f  ",c[i][j]);
        }
        printf("\n");
    }
    return 0;
}