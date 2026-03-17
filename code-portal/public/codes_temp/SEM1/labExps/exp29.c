//Count number of words in a sentence
#include <stdio.h>
#include <string.h>
int main(){
    int i,n,count=1;
    char str[150];
    printf("Enter sentence: ");
    gets(str);
    n=strlen(str);
    for(i=0;i<n;i++){
        if(str[i]==' ' && str[i+1]!=' '){
            count+=1;
        }
    }
    printf("Number of words in sentence: %d",count);
    return 0;
}