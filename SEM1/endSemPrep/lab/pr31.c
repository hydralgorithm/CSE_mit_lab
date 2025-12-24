#include <stdio.h>
#include <string.h>
int main(){
    char str[200],dstr[50],result[200];
    int i=0,j,k=0;
    gets(str);
    gets(dstr);
    while(str[i]!='\0'){
        char temp[50];
        j=0;
        while(str[i]!=' ' && str[i]!='\0'){
            temp[j++]=str[i++];
        }
        temp[j]='\0';
        if(strcmp(temp,dstr)!=0){
            int l=0;
            while(temp[l]!='\0'){
                result[k++]=temp[l++];
            }
            result[k++]=' ';
        }
        if(str[i]==' '){
            i++;
        }
    }
    // Cleanup - remove trailing space
    if(k>0 && result[k-1]==' '){
        result[k-1]='\0';
    }
    else{
        result[k]='\0';
    }
    
    printf("Result: %s\n",result);
    return 0;
}