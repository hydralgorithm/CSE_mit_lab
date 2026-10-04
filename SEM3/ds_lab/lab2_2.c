#include <stdio.h>
#include <stdlib.h>
void selSort(int *arr, int n){
    int i, smol=0, temp;
    if(n<=1){
        return;
    }
    for(int j=1; j<n; j++){
        if(*(arr+j)<*(arr+smol))
            smol = j;
    }
    temp = *(arr);
    *arr = *(arr+smol);
    *(arr+smol) = temp;
    selSort(arr+1,n-1);
}
int main(){
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    int *arr = (int *)malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        scanf("%d",arr+i);
    }
    selSort(arr,n);
    for(int i=0; i<n; i++){
        printf("%d ",*(arr+i));
    }
    printf("\n");
    return 0;
}