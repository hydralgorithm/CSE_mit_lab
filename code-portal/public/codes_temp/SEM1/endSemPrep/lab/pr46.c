#include <stdio.h>
int main(){
    FILE *f1;
    char ch;
    f1=fopen("data.txt","r");
    int c=0,w=0,l=0;
    if(f1==NULL){
        printf("error!");
        return 1;
    }
    while((ch=fgetc(f1))!=EOF){
        c++;
        if(ch==' ' || ch == '\n')
            w++;
        if(ch=='\n')
            l++;
    }
    fclose(f1);
    printf("Characters = %d\n",c);
    printf("words = %d\n",w);
    printf("Lines = %d\n",l);
    return 0;
}