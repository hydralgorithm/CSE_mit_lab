#include <stdio.h>
int main(){
    int num,rev=0,d;
    scanf("%d",&num);
    int temp=num;
    while(num!=0){
        d=num%10;
        rev=rev*10 + d;
        num=num/10;
    }
    if(temp==rev)
        printf("Palindrome!");
    else
        printf("Not Palindrome!");
    return 0;
}