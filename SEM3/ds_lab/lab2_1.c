#include <stdio.h>
#include <stdlib.h>

int findSmol(int *arr, int n){
    int smol = *arr;
    for(int i=1; i<n; i++){
        if(*(arr+i)<smol){
            smol = *(arr+i);
        }
    }
    return smol;
}
int main(){
    printf("Enter n: ");
    int n;
    scanf("%d",&n);
    int *arr = (int *)malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        scanf("%d",arr+i);
    }
    printf("Small element: %d",findSmol(arr,n));
    free(arr);
    return 0;
}