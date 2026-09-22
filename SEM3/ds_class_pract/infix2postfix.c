#include <stdio.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch){
    if(top == MAX-1){
        printf("stack overflow!");
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
    if(op == '^')
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
    for(i=0; infix[i]!='\0'; i++){
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
        } else {
            while(top!=-1 && precedence(peek())>=precedence(ch)){
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
int main(){
    char infix[MAX], postfix[MAX];
    printf("Enter infix exp: ");
    scanf("%s",infix);
    infixToPostfix(infix,postfix);
    printf("Postfix: %s",postfix);
    return 0;
}