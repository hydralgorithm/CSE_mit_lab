#include <stdio.h>
#include <ctype.h>
#define MAX 100
char stack[MAX];
int top=-1;

int InStackPrecedence(char op){
    if(op=='+'||op=='-') return 2;
    if(op=='*'||op=='/') return 4;
    if(op=='^') return 5;
    if(op=='(') return 0;
    return -1;
}
int IncomingPrecedence(char op){
    if(op=='+'||op=='-') return 1;
    if(op=='*'||op=='/') return 3;
    if(op=='^') return 6;
    if(op=='(') return 7;
    return -1;
}
void Infix_Postfix(char infix[], char postfix[]){
    int top=-1;
    int j=0;
    for(int i=0; infix[i]!='\0';i++){
        char ch = infix[i];
        if(isalnum(ch))
            postfix[j++] = ch;
        else if(ch=='(')
            stack[++top]=ch;
        else if(ch==')'){
            while(top!=-1 && stack[top]!='('){
                postfix[j++] = stack[top--];
            }
            if(top!=-1)
                top--;
        } else{
            while(top!=-1 && InStackPrecedence(stack[top])>=IncomingPrecedence(ch)){
                postfix[j++] = stack[top--];
            }
            stack[++top] = ch;
        }
    }
    while(top!=-1)
        postfix[j++] = stack[top--];
    postfix[j] = '\0';
}