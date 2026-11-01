#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct centre{
    int id;
    char name[50], loc[50];
    struct centre *lchild, *rchild;
};
typedef struct centre *cen;
struct request{
    int rid, cid, qt, priority;
    char item[30];
    struct request *next;
};
typedef struct request *req;
cen AddReliefCentre(cen t, int id, char name[], char loc[]){
    if(t==NULL){
        cen c = (cen)malloc(sizeof(struct centre));
        c->id = id;
        strcpy(c->name,name);
        strcpy(c->loc,loc);
        c->lchild = c->rchild = NULL;
        return c;
    }
    if(id<t->id)
        t->lchild = AddReliefCentre(t->lchild,id,name,loc);
    else if(id>t->id)
        t->rchild = AddReliefCentre(t->rchild,id,name,loc);
    else
        printf("Duplicate ID\n");
    return t;
}
cen SeacrhCentre(cen t,int id){
    while(t!=NULL&&t->id!=id){
        if(id<t->id) t=t->lchild;
        else t=t->rchild;
    }
    return t;
}
req SubmitRequest(cen head, req root, int rid, int cid, char item[], int qty, int pr){
    if(SeacrhCentre(root,cid)==NULL){
        printf("Invalid centre id!\n");
        return head;
    }
    
}

