#include <stdio.h>
#include <string.h>
int main(){
    char str[75];
    int i,n;
    gets(str);
    n=strlen(str);
    for(i=0;i<n;i++){
        if(str[i]>='a' && str[i]<='z'){
            str[i]-=32;
        }
        else if(str[i]>='A' && str[i]<='Z'){
            str[i]+=32;
        }
    }
    printf("%s",str);
    return 0;
}