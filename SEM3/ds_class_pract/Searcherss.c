#include <stdio.h>

int linSearch(int arr[], int n, int ele){
    for(int i=0; i<n; i++){
        if(ele==arr[i])
            return (i+1);
    }
    return -1;
}
int binSearch(int arr[], int n, int ele){
    int beg=0, end=n-1;
    while(beg<=end){
        int mid=(beg+end)/2;
        if(arr[mid]==ele){
            return (mid+1);
        } else if(arr[mid]>ele){
            end = mid-1;
        } else{
            beg = mid+1; 
        }
    }
    return -1;
}
int main(){
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    int arr[n], ch, ele;
    while(1){
        printf("1.Linear search\n");
        printf("2.Binary search\n");
        printf("3.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter arr elements:\n");
                for(int i=0; i<n; i++)
                    scanf("%d",&arr[i]);
                printf("Ele to find: ");
                scanf("%d",&ele);
                if(linSearch(arr,n,ele)!=-1)
                    printf("Ele at %d position!\n",linSearch(arr,n,ele));
                else
                    printf("Ele doesnt exist!\n");
                break;
            case 2:
                printf("Enter arr elements in sorted order:\n");
                for(int i=0; i<n; i++)
                    scanf("%d",&arr[i]);
                printf("Ele to find: ");
                scanf("%d",&ele);
                if(binSearch(arr,n,ele)!=-1)
                    printf("Ele at %d position!\n",binSearch(arr,n,ele));
                else
                    printf("Ele doesnt exist!\n");                
                break;
            case 3:
                return 0;
            default: 
                printf("Invalid choice!\n");
        }
    }
}