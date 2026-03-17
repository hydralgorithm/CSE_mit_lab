#include <stdio.h>
int main(){
    int j,a[10],i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    int beg=0,end=n-1,pos=-1,ele,mid;
    scanf("%d",&ele);
    while(beg<=end){
        mid=(beg+end)/2;
        if(ele>a[mid]){
            beg=mid+1;
        }
        else if(ele==a[mid]){
            pos=mid;
            break;
        }
        else{
            end=mid-1;
        }
    }
    if(pos==-1){
        printf("ele doesnt exist");
    }
    else{
        printf("ele exists at pos: %d",pos+1);
    }
    return 0;
}