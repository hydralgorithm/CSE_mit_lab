#include <stdio.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char ch){
    if(top == MAX-1){
        printf("stack overflow!\n");
        return;
    }
    stack[++top] = ch;
}
char pop(){
    return stack[top--];
}
char peek(){
    return stack[top];
}
int precedence(char op){
    if(op=='^')
        return 3;
    else if(op=='*' || op=='/')
        return 2;
    else if(op=='+' || op=='-')
        return 1;
    else
        return 0;
}
void infixToPostfix(char infix[], char postfix[]){
    int i, k=0;
    char ch;
    for(i=0; infix[i]!='\0';i++){
        ch = infix[i];
        if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z')){
            postfix[k++] = ch;
        } else if(ch == '('){
            push(ch);
        } else if(ch == ')'){
            while(top!=-1 && peek()!='('){
                postfix[k++] = pop();
            }
            pop();
        } else{
            while(top!=-1 && precedence(peek())>=precedence((ch))){
                postfix[k++] = pop();
            }
            push(ch);
        }
    }
    while(top!=-1){
            postfix[k++] = pop();
    }
    postfix[k] = '\0';
}
void infixToPrefix(char infix[], char prefix[]){
    char revInfix[MAX], postfix[MAX];
    strcpy(revInfix,infix);
    reverse(revInfix);
    for(int i=0; revInfix[i]!='\0'; i++){
        if(revInfix[i] == '('){
            revInfix[i] = ')';
        } else if(revInfix[i] == ')'){
            revInfix[i] = '(';
        }
    }
    top = -1;
    infixToPostfix(revInfix,postfix);
    reverse(postfix);
    strcpy(prefix, postfix);
}
int main(){
    char infix[MAX], prefix[MAX];
    printf("Enter Infix Expression: ");
    scanf("%s", infix);
    infixToPrefix(infix, prefix);
    printf("Prefix Expression: %s\n", prefix);
    return 0;
}