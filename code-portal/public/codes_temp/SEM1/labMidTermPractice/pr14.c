#include <stdio.h>
int main(){
    int a,ll,ul,i,j,flag;
    scanf("%d%d",&ll,&ul);
    for(i=ll;i<=ul;i++){
        if(i<2)
        continue;
        flag=0;
        for(j=2;j<i;j++){
            if(i%j==0){
                flag=1;
                break;
            }
        }
        if(flag==0)
            printf("%d  ",i);
    }
    return 0;
}