#include <stdio.h>

int binSearch(int arr[], int n, int key){
    int low=0, high=n-1;
    while(low<=high){
        int mid = (high+low)/2;
        if(arr[mid] == key)
            return mid+1;
        else if(arr[mid]<key)
            low = mid+1;
        else
            high = mid-1;
    }
    return -1;
}
int main(){
    int arr[5], key;
    for(int i=0; i<5; i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter key: ");
    scanf("%d",&key);
    if(binSearch(arr,5,key)==-1){
        printf("No ele\n");
    } else {
        printf("Ele at %d pos",binSearch(arr,5,key));
    }
    return 0;
}