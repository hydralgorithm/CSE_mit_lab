#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *lchild, *rchild;
};
typedef struct node *Nodeptr;
Nodeptr createTree(){
    int x;
    scanf("%d",&x);
    if(x==-1) return NULL;
    Nodeptr t = (Nodeptr)malloc(sizeof(struct node));
    t->data = x;
    t->lchild = createTree();
    t->rchild = createTree();
    return t;
}
void inorder_iter(Nodeptr curr){
    Nodeptr stack[100];
    int top=-1;
    while(curr!=NULL || top>=0){
        while(curr!=NULL){
            stack[++top] = curr;
            curr = curr->lchild;
        }
        curr = stack[top--];
        printf("%d ",curr->data);
        curr = curr->rchild;
    }
    printf("\n");
}
void preorder_iter(Nodeptr root){
    Nodeptr stack[100];
    int top=-1;
    if(root!=NULL) stack[++top] = root;
    while(top>=0){
        Nodeptr curr = stack[top--];
        printf("%d ",curr->data);
        if(curr->rchild) stack[++top] = curr->rchild;
        if(curr->lchild) stack[++top] = curr->lchild;
    }
}
void postorder_iter(Nodeptr root){
    Nodeptr s1[100], s2[100];
    int top1=-1, top2=-1;
    if(root!=NULL) s1[++top1] = root;
    while(top1>=0){
        Nodeptr curr = s1[top1--];
        s2[++top2] = curr;
        if(curr->lchild) s1[++top1] = curr->lchild;
        if(curr->rchild) s1[++top1] = curr->rchild;
    }
    while(top2>=0){
        printf("%d ",s2[top2--]->data);
    }
}
void print_parent(Nodeptr t, int key){
    if(t==NULL) return;
    if((t->lchild&&t->lchild->data==key)||(t->rchild&&t->rchild->data==key))
        printf("%d ",t->data);
    print_parent(t->lchild,key);
    print_parent(t->rchild,key);
}
int height(Nodeptr t){
    if(t==NULL) return 0;
    int l=height(t->lchild);
    int r=height(t->rchild);
    return ((l<r)?l:r)+1;
}
int print_ancestors(Nodeptr t,int key){
    if(t==NULL) return 0;
    if(t->data==key) return 1;
    if(print_ancestors(t->lchild,key) || print_ancestors(t->rchild,key)){
        printf("%d ",t->data);
        return 1;
    }
    return 0;
}
int count_leaves(Nodeptr t){
    if(t==NULL) return 0;
    if(t->lchild==NULL && t->rchild == NULL) return 1;
    return count_leaves(t->lchild)+count_leaves(t->rchild);
}
void level_order(Nodeptr root){
    Nodeptr queue[100];
    int f=0, r=0;
    if(root!=NULL) queue[r++] = root;
    while(f<r){
        Nodeptr curr = queue[f++];
        printf("%d ",curr->data);
        if(curr->lchild) queue[r++] = curr->lchild;
        if(curr->rchild) queue[r++] = curr->rchild;
    }
}
int are_equal(Nodeptr a, Nodeptr b){
    if(a==NULL && b==NULL) return 1;
    if(a==NULL || b==NULL) return 0;
    return a->data==b->data && are_equal(a->lchild,b->lchild) && are_equal(a->rchild,b->rchild);
}
int are_mirror(Nodeptr a, Nodeptr b){
    if(a==NULL&&b==NULL) return 1;
    if(a==NULL||b==NULL) return 0;
    return a->data==b->data && are_mirror(a->lchild,b->rchild)&&are_mirror(a->rchild,b->lchild);
}
Nodeptr copy(Nodeptr t){
    Nodeptr c = (Nodeptr)malloc(sizeof(struct node));
    c->data = t->data;
    c->lchild = copy(t->lchild);
    c->rchild = copy(t->rchild);
    return c;
}
int main() {
    int key;
    printf("Enter tree (-1 for NULL): ");
    Nodeptr root = create_tree();

    printf("Inorder: ");    inorder_iter(root);
    printf("\nPreorder: "); preorder_iter(root);
    printf("\nPostorder: ");postorder_iter(root);
    printf("\nLevel order: "); level_order(root);

    printf("\nEnter key: ");
    scanf("%d", &key);
    print_parent(root, key);
    printf("\nAncestors: ");
    print_ancestors(root, key);

    printf("\nHeight: %d", height(root));
    printf("\nLeaves: %d", count_leaves(root));

    Nodeptr dup = copy_tree(root);
    printf("\nCopy equal to original: %d", are_equal(root, dup));
    printf("\nCopy is mirror of original: %d\n", are_mirror(root, dup));
    return 0;
}