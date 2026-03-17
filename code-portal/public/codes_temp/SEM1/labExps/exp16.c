#include <stdio.h>
int main(){
    int flag,i,j,num,pc=0,cc=0;
    do{
        printf("Enter number :\n");
        scanf("%d",&num);
        if(num<2)
        continue;
        flag=0;
        for(j=2;j<num;j++){
            if(num%j==0){
                flag=1;
                break;
            }
        }
        if(flag==0){
            pc++;
        }
        else
            cc++;
               
    }while(num!=-1);
    printf("Count of prime numbers = %d\n",pc);
    printf("Count of composite numbers = %d\n",cc);
    return 0;
}