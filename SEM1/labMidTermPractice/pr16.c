#include <stdio.h>
int main(){
    int flag,n,cc=0,pc=0;
    do{
        scanf("%d",&n);
        if(n<2)
        continue;
        flag=0;
        for(int i=2;i<n;i++){
            if(n%i==0){
                flag=1;
                break;
            }
        }
        if(flag==0)
            pc++;
        else
            cc++;
    }while(n!=-1);
    printf("pc=%d\tcc=%d",pc,cc);
    return 0;
}