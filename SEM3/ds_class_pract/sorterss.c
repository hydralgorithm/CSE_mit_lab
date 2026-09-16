#include <stdio.h>

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

                break;
            case 4:
            
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