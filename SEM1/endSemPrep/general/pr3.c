#include <stdio.h>
int main(){
    int i,n,a[10];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int pos;
    scanf("%d",&pos);
    if(pos>n || pos<1){
        printf("Pos not accessible!");
        return 1;
    }
    else{
        // Convert 1-based position to 0-based index
        int index = pos - 1;
        for(i=index;i<n-1;i++){
            a[i]=a[i+1];
        }
        n=n-1;
        for(i=0;i<n;i++){
            printf("%d ",a[i]);
        }
    }
    return 0;
}