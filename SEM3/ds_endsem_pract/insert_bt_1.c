#include <stdlib.h>
#include <stdio.h>
struct node{
    int data;
    struct node *lchild;
    struct node *rchild;
};
typedef struct node *Nodeptr;
Nodeptr creatNode(){
    Nodeptr temp = malloc(sizeof(struct node));
    if(temp==NULL)
        exit(1);
    return temp;
}
void insertNode(Nodeptr root, char dir[], int data){
    int i=0;
    Nodeptr parent, curr, temp;
    if(root==NULL || dir[0]=='\0')
        return;
    temp = creatNode();
    temp->data = data;
    temp->lchild = temp->rchild = NULL;
    parent = NULL;
    curr = root;
    while(curr != NULL && dir[i]!='\0'){
        parent = curr;
        if(dir[i]=='L'||dir[i]=='l')
            curr = curr->lchild;
        else if(dir[i]=='R'||dir[i]=='r')
            curr = curr->rchild;
        else{
            free(temp);
            return;
        }
        i++;
    }
    if(curr!=NULL || dir[i]!='\0'){
        free(temp);
        return;
    }
    if(dir[i-1]=='L'||dir[i-1]=='l')
        parent->lchild = temp;
    else
        parent->rchild = temp;
}
int main(){
    Nodeptr root = creatNode();
    root->data = 10;
    root->lchild = root->rchild = NULL;
    insertNode(root,"L",20);
    insertNode(root,"R",30);
    insertNode(root,"LL",40);
    insertNode(root,"LR",50);
    insertNode(root,"RL",60);
    return 0;
}