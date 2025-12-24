#include <stdio.h>
int main(){
    int i,j,n,a[10];
    printf("Enter no of elements: ");
    scanf("%d",&n);
    printf("Enter ele:\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    //Ascending
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("Ascending Order:\n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    //Descending Order
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]<a[j+1]){
                int temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("\nDescending Order:\n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    return 0;
}