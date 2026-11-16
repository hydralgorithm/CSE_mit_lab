#include <stdio.h>
#define MAX 100
struct Stack{
    char arr[MAX];
    int top;
};
void push(struct Stack *st, char ch){
    if(st->top==MAX-1)
        return;
    st->arr[++st->top] = ch;
}
char pop(struct Stack *st){
    if(st->top==-1)
        return '\0';
    return st->arr[st->top--];
}
int isMatch(char open, char close){
    return (open == '(' && close ==')')||(open == '{' && close =='}')||(open == '[' && close ==']');
}
int isBal(char expr[]){
    struct Stack st;
    st.top = -1;
    for(int i=0; expr[i]!='\0';i++){
        char ch = expr[i];
        if(ch=='(')
    }
}