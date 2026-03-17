#include <stdio.h>
#include <string.h>
int main(){
    char str[200];
    scanf("%[^#]",str);
    printf("%s",str);
    return 0;
}