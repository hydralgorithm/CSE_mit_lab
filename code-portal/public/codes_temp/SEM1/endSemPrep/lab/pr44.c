#include <stdio.h>
int main(){
    FILE *f1,*f2;
    f1=fopen("source.txt","r");
    f2=fopen("target.txt","w");
    if(f1==NULL||f2==NULL){
        printf("Error!");
        return 1;
    }
    char ch;
    while((ch = fgetc(f1))!=EOF){
        fputc(ch,f2);
    }
    printf("File copied!");
    fclose(f1);
    fclose(f2);
    return 0;
}