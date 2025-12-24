#include <stdio.h>
#include <string.h>
int main(){
    char str1[200],str2[200];
    gets(str1);
    gets(str2);
    strcat(str1,str2);
    printf("%s ",str1);
    return 0;
}