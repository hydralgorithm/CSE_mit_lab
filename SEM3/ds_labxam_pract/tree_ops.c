#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
    int data;
    struct node *lchild, *rchild;
};
typedef struct node *Nodeptr;
Nodeptr getNode(int x){
    Nodeptr t = (Nodeptr)malloc(sizeof(struct node));
    t->data = x;
    t->lchild = t->rchild = NULL;
    return t;
}
void insert(Nodeptr root, char d[], int x){
    int n = strlen(d);
    Nodeptr p = root;
    for(int i=0; i<n-1; i++){
        p = (d[i]=='L')?p->lchild:p->rchild;
        if(p==NULL){printf("Not possible\n"); return;}
    }
    if (d[n-1]=='L' && p->lchild==NULL) p->lchild = getNode(x);
    else if (d[n-1]=='R' && p->rchild==NULL) p->rchild = getNode(x); 
    else printf("NP\n");
}
void inorder(Nodeptr t){
    if(t==NULL)
        return;
    inorder(t->lchild);
    printf("%d ",t->data);
    inorder(t->rchild);
}
void preorder(Nodeptr t){
    if(t==NULL)
        return;
    printf("%d ",t->data);
    preorder(t->lchild);
    preorder(t->rchild);
}
void postorder(Nodeptr t){
    if(t==NULL)
        return;
    postorder(t->lchild);
    postorder(t->rchild);
    printf("%d ",t->data);
}
int main(){
    Nodeptr root = getNode(10);
    insert(root,"L",20);
    insert(root,"R",30);
    insert(root,"LL",40);
    insert(root,"LR",50);
    insert(root,"RL",60);
    insert(root,"LLL",70);
    insert(root,"RRL",80);
    inorder(root);
    preorder(root);
    postorder(root);
    return 0;
}