#include <stdio.h>
#include <stdlib.h>

#define MAX 100
struct Stack{
    int top;
    char arr[MAX];
};
void push(struct Stack *st, char ch){
   if(st->top == MAX-1){
        printf("Stack overflow!\n");
        return;
   }
   st->arr[++st->top] = ch;
}
char pop(struct Stack *st){
    if(st->top == -1){
        printf("Stack underflow!\n");
        return '\0';
    }
    return st->arr[st->top--];
}
int isMatchingPair(char open, char close){
    return (open == '(' && close == ')') ||
        (open == '{' && close == '}') ||
        (open == '[' && close == ']');
}
int isBalanced(char *expr){
    struct Stack st;
    st.top = -1;
    for(int i=0; expr[i]!='\0'; i++){
        char ch = expr[i];
        if(ch == '(' || ch=='{' || ch=='['){
            push(&st, ch);
        } else if(ch==')' || ch=='}' || ch==']'){
            char top = pop(&st);
            if(!isMatchingPair(top,ch)){
                return 0;
            }
        }
    }
    return (st.top == -1);
}
int main(){
    char expr[MAX];
    printf("Enter expression: ");
    scanf("%s", expr);
    if(isBalanced(expr)){
        printf("Balanced!\n");
    } else {
        printf("Unbalanced!\n");
    }
    return 0;
}