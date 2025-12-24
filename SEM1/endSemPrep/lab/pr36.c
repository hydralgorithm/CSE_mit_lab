#include <stdio.h>
int main(){
    int i,a[10],max,n;
    int *ptr;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    ptr=a;
    max=*ptr;
    for(i=1;i<n;i++){
        if(*(ptr+i)>max){
            max=*(ptr+i);
        }
    }
    printf("Max value: %d",max);
    return 0;
}