#include<stdio.h>
int main(){
    char c;
    printf("\n");
    for(c='A';c<='z';c++){
        if(c>'Z' && c<'a')
            continue;
            printf("%c", c);
            printf("-");
            printf("%d", c);
            printf("\t");
    }
    return 0;
}