#include <stdio.h>
#include <stdlib.h>

int **create(int r,int c){
    int **mat = (int **)malloc(r*sizeof(int *));
    for(int i=0; i<r; i++){
        *(mat+i)=(int *)calloc(c,sizeof(int));
    }
    return mat;
}
void readMat(int **mat, int r, int c){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            scanf("%d",*(mat+i)+j);
        }
    }
}
void dispMat(int **mat, int r, int c){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            printf("%d ",*(*(mat+i)+j));
        }
        printf("\n");
    }
    printf("\n");
}
void mulMat(int **a, int **b, int **c, int m, int n, int p){
    for(int i=0; i<m; i++){
        for(int j=0; j<p; j++){
            for(int k=0;k<n;k++){
                *(*(c+i)+j) += *(*(a+i)+k) * *(*(b+k)+j);
            }
        }
    }
}
void freeMat(int **mat, int r){
    for(int i=0; i<r; i++){
        free(*(mat+i));
    }
    free(mat);
}
int main(){
    int m, n, p, **a, **b, **c;
    printf("Enter m n p: ");
    scanf("%d %d %d",&m,&n,&p);
    a=create(m,n);
    b=create(n,p);
    c=create(m,p);
    printf("Enter A: ");
    readMat(a,m,n);
    printf("Enter B: ");
    readMat(b,n,p);
    mulMat(a,b,c,m,n,p);
    printf("A:\n");
    dispMat(a,m,n);
    printf("B:\n");
    dispMat(b,n,p);
    printf("C:\n");
    dispMat(c,m,p);
    freeMat(a,m);
    freeMat(b,n);
    freeMat(c,m);
    return 0;
}