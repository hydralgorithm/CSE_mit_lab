#include <stdio.h>
int main(){
    FILE *fp;
    char text[350];
    fp = fopen("data.txt","a");
    if(fp==NULL){
        printf("Error!");
        return 1;
    }
    printf("Enter line of text to file:\n");
    fgets(text,sizeof(text),stdin);
    fputs(text,fp);
    printf("Written successful");
    fclose(fp);
    return 0;
}