#include <stdio.h>

int linSearch(int arr[], int n, int key){
    for(int i=0; i<n; i++){
        if(arr[i] == key)
            return (i+1);
    }
    return -1;
}
int main(){
    int n,key;
    printf("Enter n: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter arr elements:\n");
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter key: ");
    scanf("%d",&key);
    if(linSearch(arr,n,key) == -1)
        printf("%d does not exist!\n",key);
    else
        printf("%d exists at %d position!\n",key,linSearch(arr,n,key));
    return 0;
}