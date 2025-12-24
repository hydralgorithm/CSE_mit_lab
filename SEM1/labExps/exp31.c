//Check wheter palindrome or nah?
#include <stdio.h>
#include <string.h>
int main(){
    int n,i,flag=0;
    char str[200];
    printf("Enter string: ");
    gets(str);
    n=strlen(str);
    
    for (i=0; i<n/2;i++){
        if (str[i] != str[n - i - 1]) {
            flag = 1;
            break;
        }
    }
    if(flag==0){
        printf("Palindrome!!!");
    }
    else{
        printf("Not Palinderome!!!");
    }
    return 0;
}