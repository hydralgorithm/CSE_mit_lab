#include <stdio.h>

int main(){
    int n;
    printf("Enter dim: ");
    scanf("%d",&n);
    int matA[n][n], matB[n][n], matC[n][n];
    printf("Matrix A details:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&matA[i][j]);
        }
    }
    printf("\nMatrix B details:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&matB[i][j]);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int grt = (matA[i][j]>matB[i][j])?matA[i][j]:matB[i][j];
            matC[i][j] = grt;
        }    
    }
    printf("\nMat A disp:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ",matA[i][j]);
        }
        printf("\n");
    }
    printf("\nMat B disp:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ",matB[i][j]);
        }
        printf("\n");
    }
    printf("\nMat C disp:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ",matC[i][j]);
        }
        printf("\n");
    }
    return 0;
}