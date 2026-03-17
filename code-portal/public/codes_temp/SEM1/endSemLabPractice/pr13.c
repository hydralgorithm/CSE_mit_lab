#include <stdio.h>
int main(){
    int lim1,lim2,i,j,flag;
    printf("Enter lower and upper limit: ");
    scanf("%d%d",&lim1,&lim2);
    for(i=lim1;i<=lim2;i++){
        if(i<2)
        continue;
        flag=0;
        for(j=2;j<i;j++){
            if(i%j==0){
                flag=-1;
                break;
            }
        }
        if(flag==0)
            printf("%d ",i);
    }
    return 0;
}