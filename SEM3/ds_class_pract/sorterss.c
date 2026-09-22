#include <stdio.h>
#include <stdlib.h>
void bubSort(int arr[], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    // Display
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void selSort(int arr[], int n){
    for(int i=0; i<n; i++){
        int minIndex=i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[minIndex])
                minIndex=j;
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
    // Display
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void insertSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int key = arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j=j-1;
        }
        arr[j+1] = key;
    }
    // Display
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void merge(int arr[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));
    for(int x=0; x<n1; x++){
        L[x] = arr[l + x];
    }
    for(int x=0; x<n2; x++){
        R[x] = arr[m + 1 + x];
    }
    int i=0, j=0, k=l;
    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        } else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}
void mergeSort(int arr[], int l, int r){
    if(l<r){
        int m = l + (r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main(){
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    int arr[n], ch;
    printf("Enter arr elements:\n");
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    
    while(1){
        printf("1.Bubble sort\n");
        printf("2.Selection Sort\n");
        printf("3.Insertion Sort\n");
        printf("4.Merge Sort\n");
        printf("5.Quick Sort\n");
        printf("6.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                bubSort(arr,n);
                break;
            case 2:
                selSort(arr,n);
                break;
            case 3:
                insertSort(arr,n);
                break;
            case 4:
                mergeSort(arr, 0, n-1); 
                for(int i=0; i<n; i++)
                    printf("%d ", arr[i]);
                printf("\n");
                break;        
            case 5:
                
                break;
            case 6:
                printf("Exiting....");
                return 0;
            default: 
                printf("Invalid choice!\n");
        }
    }
}