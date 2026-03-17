#include <stdio.h>
int main(){
    int a[10],i,j,n,ele,pos=-1;
    printf("Enter arr size: ");
    scanf("%d",&n);
    printf("Enter arr ele:\n ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter ele to search and delete: ");
    scanf("%d",&ele);
    for(i=0;i<n;i++){
        if(a[i]==ele){
            pos=i;
            break;
        }
    }
    if(pos==-1){
        printf("Element does not exist!");
        return 0;
    }
    else{
        printf("Element is at %d position !",pos+1);
        for(i=pos;i<n;i++){
            a[i]=a[i+1];
        }
        n-=1;
        printf("\nArray will have now %d elements, they are:\n",n);
        for(i=0;i<n;i++){
            printf("%d ",a[i]);
        }
    }
    return 0;
}