#include <stdio.h>
#include <stdlib.h>
void readMat(int **mat, int r, int c) {
    int i, j;
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%d", *(mat + i) + j);
        }
}
void displayMat(int **mat, int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++)
            printf("%d ", *(*(mat + i) + j));
        printf("\n");
    }
}
void multiplyMat(int **A, int **B, int **C, int r1, int c1, int c2) {
    int i, j, k;
    for (i = 0; i < r1; i++)
        for (j = 0; j < c2; j++) {
            *(*(C + i) + j) = 0;
            for (k = 0; k < c1; k++)
                *(*(C + i) + j) += *(*(A + i) + k) * *(*(B + k) + j);
        }
}
int **allocMat(int r, int c) {
    int i;
    int **mat = (int **)malloc(r * sizeof(int *));
    for (i = 0; i < r; i++)
        *(mat + i) = (int *)malloc(c * sizeof(int));
    return mat;
}
void freeMat(int **mat, int r) {
    int i;
    for (i = 0; i < r; i++)
        free(*(mat + i));
    free(mat);
}
int main() {
    int r1, c1, r2, c2;
    printf("Enter rows cols of A: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows cols of B: ");
    scanf("%d %d", &r2, &c2);
    if (c1 != r2) {
        printf("Multiplication not possible\n");
        return 1;
    }
    int **A = allocMat(r1, c1);
    int **B = allocMat(r2, c2);
    int **C = allocMat(r1, c2);
    printf("Enter A:\n");
    readMat(A, r1, c1);
    printf("Enter B:\n");
    readMat(B, r2, c2);
    multiplyMat(A, B, C, r1, c1, c2);
    printf("A:\n");
    displayMat(A, r1, c1);
    printf("B:\n");
    displayMat(B, r2, c2);
    printf("A*B:\n");
    displayMat(C, r1, c2);
    freeMat(A, r1);
    freeMat(B, r2);
    freeMat(C, r1);
    return 0;
}
