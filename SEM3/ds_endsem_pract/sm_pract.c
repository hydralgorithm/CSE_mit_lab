#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int row,col,val;
} SM;

void simpleTranspose(SM a[], SM b[]){
    int k=1;
    b[0] = a[0];
    b[0].col = a[0].row;
    b[0].row = a[0].col;
    for(int c=0; c<a[0].col;c++){
        for(int i=1; i<=a[0].val; i++){
            if(a[i].col==c){
                b[k].row = a[i].col;
                b[k].col = a[i].row;
                b[k].val = a[i].val;
                k++;
            }
        }
    }
}
void fastTranspose(SM a[], SM b[]){
    int row_terms[100] = {0};
    int starting_pos[100];
    int n=a[0].val;
    int cols = a[0].col;

    b[0].row = cols;
    b[0].col = a[0].row;
    b[0].val = n;

    for(int i=1; i<=n; i++){
        row_terms[a[i].col]++;
    }
    starting_pos[0] = 1;
    for(int i=1; i<cols; i++){
        starting_pos[i] = starting_pos[i-1]+row_terms[i-1];
    }
    for(int i=1; i<=n; i++){
        int j=starting_pos[a[i].col]++;
        b[j].row = a[i].col;
        b[j].col = a[i].row;
        b[j].val = a[i].val;
    }
}