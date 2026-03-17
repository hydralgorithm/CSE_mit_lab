#include <stdio.h>
int FIB(int n){
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else
        return FIB(n-2)+FIB(n-1);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("%d ",FIB(i));
    }
    return 0;
}