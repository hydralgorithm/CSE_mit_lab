#include <stdio.h>
int main(){
    long int rev=0,num,temp,d;
    printf("Enter number: ");
    scanf("%d",&num);
    temp=num;
    while(num!=0){
        d=num%10;
        rev=rev*10+d;
        num=num/10;
    }
    if(temp==rev)
        printf("%d is a palindrome.\n",temp);
    else
        printf("%d is not a palindrome.",temp);
    return 0;
}