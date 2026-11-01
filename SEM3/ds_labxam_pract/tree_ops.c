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
void levelOrder(Nodeptr root){
    Nodeptr q[100];
    int f=0, r=0;
    if(root==NULL)
        return;
    q[r++] = root;
    while(f<r){
        Nodeptr t = q[f++];
        printf("%d ",t->data);
        if(t->lchild) q[r++] = t->lchild;
        if(t->rchild) q[r++] = t->rchild;
    }
}
int height(Nodeptr t){
    if(t==NULL) return 0;
    int l=height(t->lchild), r=height(t->rchild);
    return ((l>r)?l:r)+1;
}
int count(Nodeptr t){
    if(t==NULL) return 0;
    return 1+count(t->lchild)+count(t->rchild);
}
int leaves(Nodeptr t){
    if(t==NULL) return 0;
    if(t->lchild ==NULL && t->rchild==NULL) return 1;
    return leaves(t->lchild)+leaves(t->rchild);
}
int search(Nodeptr t,int key){
    if(t==NULL) return 0;
    if(t->data==key) return 1;
    return search(t->lchild,key) || search(t->rchild,key);
}
Nodeptr copy(Nodeptr t){
    if(t==NULL) return NULL;
    Nodeptr c = getNode(t->data);
    c->lchild = copy(t->lchild);
    c->rchild = copy(t->rchild);
    return c;
}
int equal(Nodeptr a, Nodeptr b){
    if(a==NULL && b==NULL) return 1;
    if(a==NULL || b==NULL) return 0;
    return a->data==b->data && equal(a->lchild,b->lchild) && equal(a->rchild,b->rchild);
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
    levelOrder(root);
    return 0;
}