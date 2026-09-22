#include <stdio.h>
#include <string.h>

#define MAX 100
int stack[MAX];
int top = -1;
void push(int val){
    stack[++top] = val;
}
int pop(){
    return stack[top--];
}
int evaluatePrefix(char exp[]){
    int i, op1, op2;
    for(i=strlen(exp)-1; i>=0; i--){
        char ch = exp[i];
        if(isdigit(ch)){
            push(ch -'0');
        }else{
            op1 = pop();
            op2 = pop();
            switch(ch){
                case '+': push(op1+op2);    break;
                case '-': push(op1-op2);    break;
                case '*': push(op1*op2);    break;
                case '/': push(op1/op2);    break;
                case '^': push(op1^op2);    break;
            }
        }
    }
    return pop();
}
int main(){
    char prefix[MAX];
    printf("Enter prefix: ");
    scanf("%s",prefix);
    int result = evaluatePrefix(prefix);
    printf("Result = %d\n",result);
    return 0;
}