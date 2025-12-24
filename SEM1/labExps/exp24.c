#include <stdio.h>
int main(){
    int n,pos=-1,ele,a[10],i;
    printf("Enter array size: ");
    scanf("%d",&n);
    printf("Enter array elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter element to find position and delete: ");
    scanf("%d",&ele);
    for(i=0;i<n;i++){
        if(ele==a[i]){
            pos=i;
            break;
        }
    }
    if(pos==-1){
        printf("%d not found in array\n",ele);
    }
    else{
        for(i=pos;i<n;i++){
            a[i]=a[i+1];
        }
        n=n-1;
        printf("%d found in %d position and array after deletion is \n",ele,pos+1);
        for(i=0;i<n;i++){
            printf("%d ",a[i]);
        }
    }
        
    return 0;
}