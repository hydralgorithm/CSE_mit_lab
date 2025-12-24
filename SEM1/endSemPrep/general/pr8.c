#include <stdio.h>
int main(){
    int small,pos,n,i,j,a[10];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++){
        pos=i;
        small=a[i];
        for(j=i+1;j<n;j++){
            if(small>a[j]){
                pos=j;
                small=a[pos];
            }
        }
        a[pos]=a[i];
        a[i]=small;
    }
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}