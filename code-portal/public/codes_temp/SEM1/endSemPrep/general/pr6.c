#include <stdio.h>
int main(){
    int ele,a[10],i,j,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int beg=0;
    int end=n-1;
    int pos=-1;
    scanf("%d",&ele);
    while(beg<=end){
        int mid=(beg+end)/2;
        if(ele==a[mid]){
            pos=mid;
            break;
        }
        else if(ele<a[mid]){
            end=mid-1;
        }
        else{
            beg=mid+1;
        }
    }
    if(pos==-1){
        printf("%d does not exist!",ele);
    }
    else{
        printf("%d found in %d position!",ele,pos+1);
    }
    return 0;
}