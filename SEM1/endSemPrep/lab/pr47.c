#include <stdio.h>
int main(){
    FILE *fp;
    char ch,name[50];
    printf("Enter file name: ");
    scanf("%s",name);
    fp=fopen(name,"r");
    if(fp==NULL){
        printf("Error!");
        return 1;
    }
    printf("Enter num of last characters: ");
    int n;
    scanf("%d",&n);
    fseek(fp,-n,SEEK_END);
    while((ch=fgetc(fp))!=EOF){
        putchar(ch);
    }
    fclose(fp);
    return 0;
}