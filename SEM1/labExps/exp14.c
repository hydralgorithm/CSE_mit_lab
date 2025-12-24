#include <stdio.h>
int main(){
    int flag,i,j,lim1,lim2;
    printf("Enter the lower and upper limit:\n");
    scanf("%d%d",&lim1,&lim2);
    printf("Prime numbers between %d and %d are:\n", lim1, lim2);
    for(i=lim1;i<=lim2;i++){
        if(i<2)
        continue;
        flag=0;
        for(j=2;j<i;j++){
            if(i%j==0){
                flag=1;
                break;
            }
        }
        if(flag==0){
            printf("%d ",i);
        }
    }
    return 0;
}