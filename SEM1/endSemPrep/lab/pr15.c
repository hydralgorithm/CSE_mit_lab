#include <stdio.h>
int main(){
    int count=0,cc=0,pc=0,i,j,n,flag;
    do{
        printf("Enter num: ");
        scanf("%d",&n);
        if(n==-1) break;  // Don't count sentinel value
        count+=1;
        if(n<2)
            continue;
        flag=0;
        for(i=2;i<n;i++){
            if(n%i==0){
                flag = 1;
                break;
            }
        }
        if(flag!=0){
            cc+=1;
        }
        else{
            pc+=1;
        }
    }while(n!=-1);
    printf("Number of iterations: %d\nPrime count: %d\nComposite count: %d",count,pc,cc);
    return 0;
}