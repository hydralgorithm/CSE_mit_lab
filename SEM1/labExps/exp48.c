#include <stdio.h>
int main(){
    FILE *fp;
    char name[50];
    int n;
    char ch;
    printf("Enter file name: ");
    scanf("%s",name);
    fp=fopen(name,"r");
    if(fp==NULL){
        printf("Error opening file!");
        return 1;
    }
    printf("Enter number of last characters: ");
    scanf("%d",&n);
    fseek(fp,-n,SEEK_END);
    while((ch=fgetc(fp))!=EOF){
        putchar(ch);
    }
    fclose(fp);
    return 0;
}