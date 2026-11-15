#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *lchild, *rchild;
};
struct Node *createBST(struct Node *root, int item){
    if(root==NULL){
        struct Node *temp = malloc(sizeof(struct Node));
        temp->data = item;
        temp->lchild = temp->rchild = NULL; 
        return temp;
    }
    if(item<root->data)
        root->lchild = createBST(root->lchild,item);    
    else if(item>root->data)
        root->rchild = createBST(root->rchild,item);
    return root;    
}