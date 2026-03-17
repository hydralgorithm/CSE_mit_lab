#include <stdio.h>
int main(){
    int sum=0,num,d;
    scanf("%d",&num);
    int temp = num;
    while(num!=0){
        d=num%10;
        sum = sum + (d*d*d);
        num=num/10;
    }
    if(temp == sum)
        printf("Armstrong!");
    else
        printf("Meh!");
    return 0;
}