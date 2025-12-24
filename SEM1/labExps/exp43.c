#include <stdio.h>
int main(){
    FILE *fp;
    char sentence[100];
    fp=fopen("data.txt","r");
    if(fp==NULL){
        printf("Error opening file!");
        return 1;
    }
    fgets(sentence,sizeof(sentence),fp);
    printf("Sentence from file is:\n%s",sentence);
    fclose(fp);
    return 0;
}