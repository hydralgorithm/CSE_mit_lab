#include <stdio.h>
int main(){
    FILE *fp;
    char text[100];
    fp=fopen("data.txt","a");
    if(fp==NULL){
        printf("Error opening file!");
        return 1;
    }
    printf("Enter a line of text to write into the file:\n");
    fgets(text,sizeof(text),stdin);
    fputs(text,fp);
    printf("Text successfully written to the file.\n");
    fclose(fp);
    return 0;
}