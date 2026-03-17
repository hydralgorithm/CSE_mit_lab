#include <stdio.h>
int main(){
    int temp,num,rev=0,d;
    scanf("%d",&num);
    temp=num;
    while(num!=0){
        d=num%10;
        rev=rev*10+d;
        num=num/10;
    }
    if(temp==rev)
        printf("Palindrome!");
    else   
        printf("Not Palindrome");
    return 0;
}