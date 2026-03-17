#include <stdio.h>
#include <ctype.h>
int main(){
    FILE *f1,*f2;
    char ch;
    f1=fopen("source.txt","r");
    f2=fopen("target.txt","w");
    if(f1==NULL || f2==NULL){
        printf("Error opening the file!");
        return 1;
    }
    while((ch=fgetc(f1))!=EOF){
        fputc(toupper(ch),f2);
    }
    printf("File copied in uppercase!");
    fclose(f1);
    fclose(f2);
    return 0;
}