#include <stdio.h>
#include <string.h>
int main(){
    char str[150];
    int count=0;
    gets(str);
    puts(str);
    int n = strlen(str);
    for(int i=0;i<n;i++){
        count+=1;
    }
    printf("Characters: %d",count);
    return 0;
}