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
    if(x<t->data)
        t->lchild = insert(t->lchild,x);
    else if(x>t->data)
        t->rchild = insert(t->rchild,x);
    return t;
}
Nodeptr search(Nodeptr t, int x){
    while(t!=NULL && t->data != x){
        if(x<t->data) t=t->lchild;
        if(x>t->data) t=t->rchild;
    }
    return t;
}
Nodeptr find_min(Nodeptr t){
    while(t->lchild!=NULL) t = t->lchild;
    return t;
}
Nodeptr find_max(Nodeptr t){
    while(t->rchild!=NULL) t=t->rchild;
    return t;
}
Nodeptr delete_node(Nodeptr t, int x){
    if(t==NULL) return NULL;
    if(x<t->data) 
        t->lchild = delete_node(t->lchild,x);
    else if(x>t->data)
        t->rchild = delete_node(t->rchild,x);
    else{
        if(t->lchild==NULL){
            Nodeptr r = t->rchild;
            free(t);
            return r;
        }
        if(t->rchild==NULL){
            Nodeptr l = t->lchild;
            free(t);
            return l;
        }
        Nodeptr s =find_min(t->rchild);
        t->data = s->data;
        t->rchild = delete_node(t->rchild,s->data);
    }
    return t;
}