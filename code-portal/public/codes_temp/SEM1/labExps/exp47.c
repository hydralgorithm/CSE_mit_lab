#include <stdio.h>
int main(){
    FILE *fp;
    char ch;
    int c=0,w=0,l=0;
    fp=fopen("data.txt","r");
    if(fp==NULL){
        printf("Error opening file!");
        return 1;
    }
    while((ch=getc(fp))!=EOF){
        c++;
        if(ch==' '||ch=='\n')
            w++;
        if(ch=='\n')
            l++;
    }
    fclose(fp);
    printf("Characters = %d\n",c);
    printf("Words = %d\n",w);
    printf("Lines = %d",l);
    return 0;
}