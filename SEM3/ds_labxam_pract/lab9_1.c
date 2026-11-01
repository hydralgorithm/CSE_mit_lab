#include <stdio.h>
struct node{
    int data;
    struct node *left, *right;
};
void preorder(struct node *root){
    struct node *stack[100];
    int top=-1;
    if(root==NULL)
        return;
    stack[++top] = root;
    while(top!=-1){
        struct node *temp = stack[top--];
        printf("%d ",temp->data);
        if(temp->right!=NULL)
            stack[++top] = temp->right;
        if(temp->left!=NULL)
            stack[++top] = temp->left;
    } 
}
void inorder(struct node *root){
    if(root==NULL)  
        return;
    struct node *stack[100];
    int top=-1;
    struct node *curn = root;
    while(curn!=NULL && top!=-1){
        while(curn!=NULL){
            stack[++top] = curn;
            curn = curn->left;
        }
        curn = stack[top--];
        printf("%d ",curn->data);
        curn = curn->right;
    }
}
void postorder(){
    
}
int main(){
    
    return 0;
}
