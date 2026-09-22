#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
bool is_duplicate(char s[]){
    char Stack[MAX_SIZE];
    int top = -1;
    int n = strlen(s);
    for(int i=0; i<n; i++){
        if(s[i] == ')'){
            int elementsInside = 0;
            while(top!=-1 && Stack[top]!='('){
                elementsInside++;
                top--;
            }
            if(top!=-1){
                top--;
            }
            if(elementsInside<1){
                return true;
            }
        } else {
            Stack[++top] = s[i];
        }
    } 
    return false;
}
int main(){
    char expr1[] = "((a+b))";
    char expr2[] = "(a+(b)/c)";
    printf("Expression: %s -> %s\n", expr1, is_duplicate(expr1) ? "Duplicate Found" : "No Duplicate");
    printf("Expression: %s -> %s\n", expr2, is_duplicate(expr2) ? "Duplicate Found" : "No Duplicate");
    
    return 0;
}
