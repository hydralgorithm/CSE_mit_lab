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
Nodeptr search(Nodeptr root, int key){
    if(root==NULL)return NULL;
    if(root->data==key)return root;
    Nodeptr p = search(root->lchild,key);
    if(p!=NULL){
        return p;
    }
    return search(root->rchild,key);
}
Nodeptr insert(Nodeptr root, int parent, int ch, int x){
    Nodeptr p= search(root,parent);
    if(p==NULL) return root;
    Nodeptr t = new_node(x);
    if(ch==1 && p->lchild==NULL)
        p->lchild = t;
    else if(ch==2 && p->rchild==NULL)
        p->rchild = t;
    else
        free(t);
    return root;
}
void preorder(Nodeptr root){
    if(root==NULL)return;
    printf("%d ",root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}
int count_nodes(Nodeptr root, int key){
    if(root == NULL) return 0;
    if(root->data == key) return 1;
    int left = count_nodes(root->lchild,key);
    if(left!=0) return left+1;
    int right = count_nodes(root->rchild,key);
    if(right!=0) return right+1;
    return 0;
}
int height(Nodeptr t){
    if(t==NULL) return -1;
    int l = height(t->lchild);
    int r = height(t->rchild);
    return (l>r?l:r)+1;
}
int main(){
    Nodeptr root = new_node(50);
    insert(root,50,1,20);
    insert(root,20,2,30);
    insert(root,50,2,15);
    preorder(root);
    printf("%d",count_nodes(root,50));
    printf("%d",height(root));
    return 0;
}