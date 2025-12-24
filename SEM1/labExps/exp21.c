#include <stdio.h>
int main(){
    int a[10],n,i,small,lar;
    printf("Enter array size: ");
    scanf("%d",&n);
    printf("Enter array elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    lar=a[0];
    small=a[0];
    for(i=1;i<n;i++){
        if(a[i]>lar)
            lar=a[i];
        if(a[i]<small)
            small=a[i];
    }
    printf("Largest element: %d\n",lar);
    printf("Smallest element: %d",small);
    return 0;
}