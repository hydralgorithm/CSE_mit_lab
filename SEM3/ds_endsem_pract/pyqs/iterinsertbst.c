#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *lchild, *rchild;
};
typedef struct node *Nodeptr;
Nodeptr iter_insert(Nodeptr root, int val){
    Nodeptr temp = malloc(sizeof(struct node));
    temp->data = val;
    temp->lchild = temp->rchild = NULL;
    if(root==NULL)
        return temp;
    Nodeptr curn = root, parent = NULL;
    while(curn!=NULL){
        parent = curn;
        if(val<curn->data)
            curn = curn->lchild;
        else if(val>curn->data)
            curn = curn->rchild;
        else{
            free(temp);
            return root;
        }
    }
    if(val<parent->data)
        parent->lchild = temp;
    else
        parent->rchild = temp;
    return root;
}