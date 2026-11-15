#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *lchild, *rchild;
};
typedef struct node *Nodeptr;
Nodeptr createNode(int data){
    Nodeptr temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->lchild = temp->rchild = NULL;
    return temp;
}
Nodeptr insertRec(Nodeptr root, int item){
    if(root == NULL)
        return createNode(item);
    if(item<root->data)
        return insertRec(root->lchild,item);
    else if(item>root->data)
        return insertRec(root->rchild,item);
    return root;
}
Nodeptr searchRec(Nodeptr root, int key){
    if(root==NULL || root->data==key)
        return root;
    if(key<root->data)  
        return searchRec(root->lchild,key);
    return searchRec(root->rchild,key);
}
Nodeptr insertIter(Nodeptr root, int item){
    Nodeptr temp = createNode(item);
    Nodeptr curr = root, parent = NULL;
    if(root==NULL)
        return temp;
    while(curr!=NULL){
        parent = curr;
        if(item<curr->data)
            curr=curr->lchild;
        else if(item>curr->data)
            curr = curr->rchild;
        else
            free(temp);
            return root;
    }
    if(item<parent->data)
        parent->lchild = temp;
    else
        parent->rchild = temp;
    return root;
}
Nodeptr searchIter(Nodeptr root, int key){
    while(root!=NULL){
        if(root->data==key)
            return root;
        if(key<root->data)
            root = root->lchild;
        else
            root = root->rchild;
    }
    return NULL;
}
Nodeptr Delete(Nodeptr root, int item){
    Nodeptr curr = root, parent = NULL;
    Nodeptr succ, q;
    while(curr!=NULL && curr->data!=item){
        parent = curr;
        if(item<curr->data)
            curr = curr->lchild;
        else
            curr = curr->rchild;
    }
    if(curr==NULL)
        return root;
    if(curr->lchild==NULL)
        q = curr->rchild;
    else if(curr->rchild==NULL)
        q = curr->rchild;
    else{
        parent = curr;
        succ = curr->rchild;
        while(succ->lchild!=NULL){
            parent = succ;
            succ = succ->lchild;
        }
        curr->data = succ->data;
        curr = succ;
        q = curr->rchild;
    }
     
}