//Delete word from given sentence
#include <stdio.h>
#include <string.h>
int main(){
    int i=0,j,k=0;
    char sstr[200],dstr[50],result[200];
    printf("Enter sentence: ");
    gets(sstr);
    printf("Enter word to delete: ");
    gets(dstr);
    while(sstr[i]!='\0'){
        char temp[50];
        j=0;
        while(sstr[i]!=' ' && sstr[i]!='\0'){
            temp[j++] = sstr[i++];
        }
        temp[j]='\0';

        if(strcmp(temp,dstr)!=0){
            int l=0;
            while(temp[l] != '\0'){
                result[k++] = temp[l++];
            }
            result[k++]=' ';
        }
        if (sstr[i]==' '){
            i++;
        }
    }
    if(k>0 && result[k-1]==' '){
        result[k-1]='\0';
    }
    else{
        result[k]='\0';
    }
    printf("Sentence after deleting word: %s\n",result);
    return 0;
}