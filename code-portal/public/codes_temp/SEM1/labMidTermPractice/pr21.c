#include <stdio.h>
int main(){
    int a[10],n,temp,i,j,lar,small;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    lar=a[0];
    small=a[0];
    for(i=0;i<n;i++){
        if(lar<=a[i]){
            temp=lar;
            lar=a[i];
            a[i]=temp;
        }
        else if(small>a[i]){
            temp=small;
            small=a[i];
            a[i]=temp;
        }
    }
    printf("LARGE = %d\tSMALL = %d",lar,small);
    return 0;
}