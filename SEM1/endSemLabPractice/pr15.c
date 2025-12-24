#include <stdio.h>
int main(){
    int cc=0,pc=0,num,flag,i,j;
    do{
        printf("Enter number: ");
        scanf("%d",&num);
        if(num<2)
            continue;
        flag=0;
        for(i=2;i<num;i++){
            if(num%i==0){
                flag=-1;
                break;
            }
        }
        if(flag==0){
            pc+=1;
        }
        else
            cc+=1;
    }while(num!=-1);
    printf("Prime count = %d\nComposite count = %d\n",pc,cc);
    return 0;
}