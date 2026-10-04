#include <stdio.h>

void bubSort(int arr[], int n){
    
}
void selSort(int arr[], int n){

}
void insertSort(int arr[], int n){

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
    prinf("\n1.Bubble sort\n2.Selection sort\n3.Insertion sort\nEnter choice: ");
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