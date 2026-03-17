#include <stdio.h>
#include <string.h>
int main(){
    char ch,pw[10],un[10];
    int i;
    
    printf("Enter username: ");
    fgets(un,sizeof(un),stdin);
    
    // Remove newline from username
    int len = strlen(un);
    if(len > 0 && un[len-1] == '\n'){
        un[len-1] = '\0';
    }

    printf("Enter password (6 characters): ");
    for(i=0;i<6;i++){
        pw[i]=getchar();  // Read from stdin, not from ch
        printf("*");      // Print asterisk to hide character
    }
    pw[6]='\0';  // Null-terminate the password string
    
    printf("\nUsername: %s\n",un);
    printf("Password: %s\n",pw);
    return 0;
}