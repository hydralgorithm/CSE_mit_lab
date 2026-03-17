#include <stdio.h>
int main(){
    int i,n,a[10];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int lar = a[0];
    int small=a[0];
    for(i=1;i<n;i++){
        if(lar<=a[i]){
            lar=a[i];
        }
        if(small>a[i]){
            small=a[i];
        }
    }
    printf("Largest = %d\nSmallest = %d\n",lar,small);
    return 0;
}