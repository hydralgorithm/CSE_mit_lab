#include <stdio.h>
int main(){
    int n,a[10],i,j,temp,choice;
    printf("Enter array size: ");
    scanf("%d",&n);
    printf("Enter array elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Choose 1 for ascending and 2 for descending:\n");
    scanf("%d",&choice);
    switch(choice){
        case 1: for(i=0;i<n-1;i++){
                    for(j=0;j<n-i-1;j++){
                        if(a[j]>a[j+1]){
                            temp=a[j];
                            a[j]=a[j+1];
                            a[j+1]=temp;
                        }
                    }
                }
                printf("Array in ascending order:\n");
                for(i=0;i<n;i++){
                    printf("%d ",a[i]);
                }
                break;
        case 2: for(i=0;i<n-1;i++){
                    for(j=0;j<n-i-1;j++){
                        if(a[j]<a[j+1]){
                            temp=a[j];
                            a[j]=a[j+1];
                            a[j+1]=temp;
                        }
                    }
                } 
                printf("Array in descending order:\n");
                for(i=0;i<n;i++){
                    printf("%d ",a[i]);
                }
                break;
        default : printf("Error !");
    }
    
    return 0;
}