#include <stdio.h>
int main(){
    int i,n,a[10],ele,pos=-1;  // Fix 1: Initialize pos to -1
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
    if(pos==-1){  // Fix 1: Check if pos is -1 (not found)
        printf("Ele not in array!");
    }
    else{
        for(i=pos;i<n;i++){
            a[i]=a[i+1];
        }
        n=n-1;
        printf("Array after deletion: ");
        for(i=0;i<n;i++){
            printf("%d ",a[i]);  // Fix 2: Print value, not address, with space
        }
        printf("\n");
    }
    return 0;
}