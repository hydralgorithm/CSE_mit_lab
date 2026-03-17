#include <stdio.h>
#include <string.h>
int main(){
    char str[150];
    int w=0;
    fgets(str,sizeof(str),stdin);
    
    // Remove newline if present
    int n=strlen(str);
    if(n > 0 && str[n-1] == '\n'){
        str[n-1] = '\0';
        n--;
    }
    // Count words using state-based approach
    int inWord = 0;  // Flag to track if we're inside a word
    
    for(int i=0;i<n;i++){
        if(str[i] != ' ' && str[i] != '\t'){  // Non-whitespace character
            if(!inWord){  // Start of a new word
                w++;
                inWord = 1;
            }
        }
        else{  // Whitespace character
            inWord = 0;  // End of current word
        }
    }
    printf("Words = %d",w);
    return 0;
}