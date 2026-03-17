#include <stdio.h>
int main(){
    int lar,small,a[10],i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    small=a[0];
    lar=a[0];
    for(i=0;i<n;i++){
        if(lar<=a[i])
            lar=a[i];
        else if(small>a[i])
            small=a[i];
    }
    printf("Largest = %d\nSmallest = %d",lar,small);
    return 0;
}