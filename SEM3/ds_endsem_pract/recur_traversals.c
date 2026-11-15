#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *lchild;
    struct node *rchild;
};
typedef struct node *Nodeptr;
Nodeptr createNode(int data){
    Nodeptr temp = malloc(sizeof(struct node));
    if(temp==NULL)
        exit(1);
    temp->data = data;
    temp->lchild = temp->rchild = NULL;
    return temp;
}
void inorder(Nodeptr root){
    if(root==NULL)
        return;
    inorder(root->lchild);
    printf("%d ",root->data);
    inorder(root->rchild);
}
void preorder(Nodeptr root){
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}
void postorder(Nodeptr root){
    if(root==NULL)
        return;
    preorder(root->lchild);
    preorder(root->rchild);
    printf("%d ",root->data);
}
#define MAX 100
Nodeptr queue[MAX];
int front = 0, rear=-1;
void enqueue(Nodeptr temp){
    if(rear==MAX-1)
        return;
    queue[++rear] = temp;
}
Nodeptr dequeue(){
    if(front>rear)
        return NULL;
    return queue[front++];
}
void levelOrder(Nodeptr root){
    if(root==NULL)
        return;
    front = 0;
    rear = -1;
    enqueue(root);
    while(front<=rear){
        Nodeptr curr = dequeue();
        printf("%d ",curr->data);
        if(curr->lchild!=NULL)
            enqueue(curr->lchild);
        if(curr->rchild!=NULL)
            enqueue(curr->rchild);
    }
}
int main(){
    Nodeptr root = createNode(10);
    root->lchild = createNode(5);
    root->rchild = createNode(78);
    root->rchild->lchild = createNode(90);
    root->rchild->rchild = createNode(88);
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    levelOrder(root);
    printf("\n");
    return 0;
}