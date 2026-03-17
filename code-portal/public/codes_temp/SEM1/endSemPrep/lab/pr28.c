#include <stdio.h>
#include <string.h>
int main(){
    int i,count=0;
    char str[100];
    gets(str);
    int n = strlen(str);
    for(i=0;i<n;i++){
        if(str[i] == ' ' && str[i+1]!=' '){
            count+=1;
        }
    }
    printf("Number of words = %d",count);
    return 0; 
}