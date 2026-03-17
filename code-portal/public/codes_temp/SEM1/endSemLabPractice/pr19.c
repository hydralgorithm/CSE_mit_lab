#include <stdio.h>
int main(){
    int sum=0,i,num,temp;
    scanf("%d",&num);
    temp=num;
    for(i=1;i<=num/2;i++){
        if(num%i==0){
            sum+=i;
        }
    }
    if(temp==sum){
        printf("Perfect!");
    }
    else
        printf("Not perfect!");
    return 0;
}