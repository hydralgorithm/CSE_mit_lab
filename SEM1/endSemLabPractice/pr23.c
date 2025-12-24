#include <stdio.h>
int main(){
    int i,n,a[10],pos=-1,ele;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&ele);
    for(i=0;i<n;i++){
        if(ele==a[i]){
            pos=i;
            break;
        }
    }
    if(pos==-1)
        printf("Element does not exist!\n");
    else{
        for(i=pos;i<n;i++){
            a[i]=a[i+1];
        }
        n=n-1;
        printf("%d found in %d position and array after deletion is: \n",ele,pos+1);
        for(i=0;i<n;i++){
            printf("%d ",a[i]);
        }
    }
    
    return 0;
}