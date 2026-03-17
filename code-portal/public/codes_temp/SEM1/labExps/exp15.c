#include <stdio.h>
int main(){
    int d,rev=0,num,temp,sum=0;
    printf("Enter number: ");
    scanf("%d",&num);
    temp=num;
    while(num!=0){
        d=num%10;
        sum=sum+(d*d*d);
        num=num/10;
    }
    if(temp==sum){
        printf("%d is an armstrong number.",temp);
    }
    else{
        printf("Not an armstrong number");
    }
    return 0;
}