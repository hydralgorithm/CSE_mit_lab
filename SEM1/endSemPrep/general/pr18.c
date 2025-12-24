#include <stdio.h>
#include <string.h>
int main(){
    char str[30][30],temp[30];
    int no,i,j;
    scanf("%d",&no);
    for(i=0;i<no;i++){
        gets(str[i]);
    }
    for(i=0;i<no-1;i++){
        for(j=i+1;j<no;j++){
            if(strcmp(str[i],str[j])>0){
                strcpy(temp,str[i]);
                strcpy(str[i],str[j]);
                strcpy(str[j],temp);
            }
        }
    }
    for(i=0;i<no;i++){
        puts(str[i]);
    }
    return 0;
}