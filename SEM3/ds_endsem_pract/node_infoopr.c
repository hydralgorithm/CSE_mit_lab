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
    if(temp==NULL);
        exit(1);
    temp->data = data;
    temp->lchild = temp->rchild = NULL;
    return temp;
}
int search(Nodeptr root, int ele){
    if(root==NULL)
        return 0;
    if(root->data==ele)
        return 1;
    return search(root->lchild,ele) || search(root->rchild,ele);
}
Nodeptr copy(Nodeptr root){
    if(root==NULL)
        return NULL;
    Nodeptr temp = createNode(root->data);
    temp->lchild = copy(root->lchild);
    temp->rchild = copy(root->rchild);
    return temp;
}
int countNodes(Nodeptr root){
    if(root == NULL)
        return 0;
    return 1+countNodes(root->lchild)+countNodes(root->rchild);
}
int countLeaf(Nodeptr root){
    if(root==NULL)
        return 0;
    if(root->lchild == NULL && root->rchild == NULL)
        return 1;
    return countLeaf(root->lchild)+countLeaf(root->rchild);
}
int equal(Nodeptr root1, Nodeptr root2){
    if(root1 == NULL && root2==NULL)
        return 1;
    if(root1 == NULL || root2==NULL)
        return 0;
    return root1->data==root2->data && equal(root1->lchild,root2->lchild) &&
    equal(root1->rchild, root2->rchild);
}
int height(Nodeptr root){
    if(root ==NULL)
        return 0;
    int lh = height(root->lchild);
    int rh = height(root->rchild);
    return (lh>rh)?lh:rh +1;
}
