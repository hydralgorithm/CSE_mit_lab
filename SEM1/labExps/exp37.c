#include <stdio.h>
int main(){
    int max,n,a[20];
    int *ptr;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter %d integers:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    ptr=a;
    max=*ptr;
    for(int i=1;i<n;i++){
        if(*(ptr+i)>max)
            max=*(ptr+i);
    }
    printf("The maximum number is %d\n",max);
    return 0;
}