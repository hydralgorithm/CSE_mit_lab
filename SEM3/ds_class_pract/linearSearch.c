#include <stdio.h>

int linearSearch(int arr[], int n, int target){
    for(int i=0; i<n; i++){
        if(arr[i] == target)
            return i+1;
    }
    return -1;
}

int main(){
    int n, ele;
    // printf("Enter array size n: ");
    // scanf("%d", &n);
    printf("Enter element to find: ");
    scanf("%d", &ele);
    printf("Enter 5 array elements:\n");
    int hi[5];
    for(int i=0; i<5; i++){
        scanf("%d", &hi[i]);
    }
    int verdict = linearSearch(hi,5,ele);
    if(verdict==-1){
        printf("Element doesn't exist.");
    } else {
        printf("Element %d exists at position %d",ele,verdict);
    }
    return 0;
}