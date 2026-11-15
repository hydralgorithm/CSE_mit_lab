#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

struct node{
    char data;
    struct node *lchild;
    struct node *rchild;
};
typedef struct node *Nodeptr;
Nodeptr createNode(char data){
    Nodeptr temp = malloc(sizeof(struct node));
    if(temp==NULL)
        exit(1);
    temp->data = data;
    temp->lchild = temp->rchild = NULL;
    return temp;
}
Nodeptr stack[100];
int top = -1;
void push(Nodeptr temp){
    stack[++top] = temp;
}
Nodeptr pop(){
    return stack[top--];
}
Nodeptr createTree(char postfix[]){
    top = -1;
    for(int i=0; postfix[i]!='\0'; i++){
        char ch = postfix[i];
        Nodeptr temp = createNode(ch);
        if(isalnum(ch))
            push(temp);
        else{
            temp->rchild = pop();
            temp->lchild = pop();
            push(temp);
        }
    }
    return pop();
}
double eval(Nodeptr root){
    if(isdigit(root->data))
        return root->data - '0';
    double left = eval(root->lchild);
    double right = eval(root->rchild);
    switch(root->data){
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/': return left / right;
        case '^': return pow(left,right);
        default: return 0;
    }
}
int main(){
    char postfix[] = "53-4*9+";

    Nodeptr root = createTree(postfix);

    printf("Result = %.2f", eval(root));

    return 0;
}