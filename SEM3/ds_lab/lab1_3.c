#include <stdio.h>

void bubSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void selSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[minIndex])
                minIndex = j;
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
void insertSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
void displaY(int arr[], int n){
    for(int i=0; i<n; i++)
        printf("%d ",arr[i]);
    printf("\n");
}
int main(){
    int n,ch;
    printf("Enter n: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    printf("\n1.Bubble sort\n2.Selection sort\n3.Insertion sort\nEnter choice: ");
    scanf("%d",&ch);
    switch(ch){
        case 1:
            bubSort(arr,n);
            displaY(arr,n);
            break;
        case 2:
            selSort(arr,n);
            displaY(arr,n);
            break;
        case 3:
            insertSort(arr,n);
            displaY(arr,n);
            break;
        default:
            printf("Invalid!\n");   
    }
    return 0;
}