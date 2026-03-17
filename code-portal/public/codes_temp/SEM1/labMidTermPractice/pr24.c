#include <stdio.h>
int main(){
    int ele,pos=-1,n,i,j,a[10];
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
    if (pos==-1)
    {
        printf("Ele not found");
    }
    else{
        for(i=pos;i<n;i++){
            a[i]=a[i+1];
        }
        n=n-1;
        for(i=0;i<n;i++){
            printf("%d ",a[i]);
        }
        printf("\n%d",pos+1);
    }
    return 0;
}