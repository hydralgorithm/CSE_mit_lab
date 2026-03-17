#include <stdio.h>
int main(){
    int a[10],i,j,n,ele,pos,beg,end,mid,temp;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    scanf("%d",&ele);
    beg=0;
    end=n-1;
    pos=-1;
    while(beg<=end){
        mid=(beg+end)/2;
        if(a[mid]==ele){
            pos=mid;
            break;
        }
        else if(a[mid]>ele){
            end=mid-1;
        }
        else{
            beg=mid+1;
        }
    }
    if(pos==-1){
        printf("ele does not exist");
    }
    else{
        printf("Its at %d position",pos+1);
    }
    return 0;
}