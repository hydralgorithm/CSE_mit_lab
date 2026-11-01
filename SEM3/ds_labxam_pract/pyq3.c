#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *lchild, *rchild;
};
typedef struct node *Nodeptr;
Nodeptr new_node(int x){
    Nodeptr t = (Nodeptr)malloc(sizeof(struct node));
    t->data = x;
    t->lchild = t->rchild = NULL;
    return t;
}
Nodeptr insert(Nodeptr t, int x){
    if(t==NULL) return new_node(x);
    if(x<t->data) t->lchild = insert(t->lchild, x);
    else if(x>t->data) t->rchild = insert(t->rchild, x);
    else printf("Duplicate not allowed!");
    return t;
}
Nodeptr find_min(Nodeptr t){
    while(t->lchild!=NULL) t=t->lchild;
    return t;
}
Nodeptr delete_node(Nodeptr t, int x){
    if(t==NULL) return NULL;
    if(x<t->data) t->lchild = delete_node(t->lchild, x);
    else if(x>t->data) t->rchild = delete_node(t->rchild,x);
    else{
        if(t->lchild == NULL){
            Nodeptr r = t->rchild;
            free(t);
            return r;
        }
        if(t->rchild == NULL){
            Nodeptr l = t->lchild;
            free(t);
            return l;
        }
        Nodeptr s = find_min(t->rchild);
        t->data = s->data;
        t->rchild =delete_node(t->rchild,s->data);
    }
    return t;
}
void inorder(Nodeptr t){
    if(t==NULL) return;
    inorder(t->lchild);
    printf("%d ",t->data);
    inorder(t->rchild);
}
int main(){
    Nodeptr root = new_node(10);
    insert(root,20);
    insert(root,5);
    insert(root,30);
    insert(root,27);
    inorder(root);
    delete_node(root,30);
    inorder(root);
    return 0;
}