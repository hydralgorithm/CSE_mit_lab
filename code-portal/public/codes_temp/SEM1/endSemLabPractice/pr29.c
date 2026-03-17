#include <stdio.h>
#include <string.h>
int main(){
    int n;
    char str[150];
    gets(str);
    n=strlen(str);
    for(int i=0;i<n;i++){
        if(str[i]>='a' && str[i]<='z'){
            str[i]=str[i]-32;
        }
        else if(str[i]>='A' && str[i]<='Z'){
            str[i]=str[i]+32;
        }
    }
    printf("Toggled: %s",str);
    return 0;
}