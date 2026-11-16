#include <stdio.h>
#include <ctype.h>

char stack[100];
int top=-1;

int InStackPrecedence(char op){
    if(op=='^') return 3;
    if(op=='*'||op=='/') return 2;
    if(op=='+'||op=='-') return 1;
    return 0;
}
int IncomingPrecedence(char op) {
    if(op=='^') return 4;
    return InStackPrecedence(op);
}
void Infix_Postfix(char infix[], char postfix[]) {
    int i,j=0;
    char ch;
    top=-1;
    for(i=0;infix[i]!='\0';i++){
        ch = infix[i];
        if(isalnum(ch)){
            postfix[j++] = ch;
        } else if(ch=='('){
            stack[++top] = ch;
        } else if(ch==')'){
            while(top!=-1 && stack[top]!='('){
                postfix[j++] = stack[top--];
            }
            if(top!=-1)
                top--;
        } else{
            while(top!=-1 && stack[top]!='(' && InStackPrecedence(stack[top])>=IncomingPrecedence(ch))
                postfix[j++] = stack[top--];
            stack[++top] = ch;
        }
    }
}