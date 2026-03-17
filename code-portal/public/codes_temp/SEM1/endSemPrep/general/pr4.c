#include <stdio.h>
int main(){
    int a[]={1,2,4,5};
    int pos,ele,n=4;
    pos = n+1;  // Initialize pos for end insertion (if element is largest)
    scanf("%d",&ele);
    for(int i=0;i<n;i++){
        if(ele<a[i]){
            pos=i;  // Found position - element should go before a[i]
            break;
        }
    }
        for(int i=n;i>=pos;i--){
            a[i]=a[i-1];
        }
        a[pos] = ele;
        n=n+1;
        for(int i=0;i<n;i++){
            printf("%d ",a[i]);
        }

    return 0;
}