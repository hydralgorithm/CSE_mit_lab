#include <stdio.h>
int main(){
    int choice,n,i,j,a[10],temp;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
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
                for(i=0;i<n;i++){
                    printf("%d ",a[i]);
                }
                break;
        default: printf("WRONG CHOICE!");

    }
    return 0;
}