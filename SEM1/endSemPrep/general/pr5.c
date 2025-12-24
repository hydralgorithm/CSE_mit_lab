#include <stdio.h>
int main(){
    int n,a[10],i,pos,ele,flag=-1;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&ele);
    for(i=0;i<n;i++){
        if(a[i]==ele){
            pos=i;flag=0;
            break;
        }
    }
    if(flag==0){
        printf("%d at %d position!",ele,pos+1);
    }
    else
        printf("%d not in array!",ele);
    return 0;
}