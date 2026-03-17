#include <stdio.h>
int main(){
    int flag,i,n,a[10],j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        if(a[i]<2)
            continue;
        flag=0;
        for(j=2;j<a[i];j++){
            if(a[i]%j==0){
                flag=1;
                break;
            }
        }
        if(flag==0)
            printf("%d ",a[i]);
    }
    return 0;
}