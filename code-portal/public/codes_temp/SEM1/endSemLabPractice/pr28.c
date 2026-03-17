#include <stdio.h>
#include <string.h>
int main(){
    int count=1,i,n;
    char str[150];
    gets(str);
    n=strlen(str);
    for(i=0;i<n;i++){
        if(str[i]==' ' && str[i+1]!=' '){
            count+=1;
        }
    }
    printf("count = %d",count);
    return 0;
}