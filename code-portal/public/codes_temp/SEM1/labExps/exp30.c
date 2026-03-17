//toggle case of every character in input string
#include <stdio.h>
#include <string.h>
int main(){
    char str[200];
    int i,n;
    printf("Enter string: ");
    gets(str);
    n=strlen(str);
    for(i=0;i<n;i++){
        if(str[i]>='a' && str[i]<='z'){
            str[i]=str[i]-32;
        }
        else if(str[i]>='A' && str[i]<='Z'){
            str[i]=str[i]+32;
        }
    }
    printf("The toggled string is: %s",str);
    return 0;
}