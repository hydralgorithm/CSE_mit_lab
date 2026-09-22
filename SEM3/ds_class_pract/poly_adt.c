#include <stdlib.h>
#include <stdio.h>

struct poly{
    int coef;
    int power;
    struct poly *next;
};
struct poly *list1 = NULL, *list2 = NULL, *list3 = NULL;

struct poly *create(struct poly *h, int c, int p){
    struct poly *n = (struct poly *)malloc(sizeof(struct poly));
    n->coef = c;
    n->power = p;
    n->next = NULL;
    if(h == NULL){
        h=n;
    } else {
        struct poly *pt = h;
        while(pt->next!=NULL){
            pt = pt->next;
        }
        pt->next = n;
    }
    return h;
}
struct poly *add(struct poly *list1, struct poly *list2){
    struct poly *pt1 = list1, *pt2 = list2;
    struct poly *list3=NULL;
    while(pt1!=NULL && pt2!=NULL){
        if(pt1->power == pt2->power){
            list3 = create(list3, pt1->coef + pt2->coef, pt1->power);
            pt1 = pt1->next;
            pt2 = pt2->next;
        } else if(pt1->power > pt2->power){
            list3 = create(list3, pt1->coef, pt1->power);
            pt1 = pt1->next;
        } else {
            list3 = create(list3, pt2->coef, pt2->power);
            pt2 = pt2->next;
        }
    }
    while(pt1 != NULL){
        list3 = create(list3, pt1->coef, pt1->power);
        pt1 = pt1->next;
    }
    while(pt2 != NULL){
        list3 = create(list3, pt2->coef, pt2->power);
        pt2 = pt2->next;
    }
    return list3;
}
void display(struct poly *h){
    struct poly *ptr = h;
    while(ptr!=NULL){
        printf(" %dx^%d ",ptr->coef, ptr->power);
        ptr = ptr->next;
        if(ptr!=NULL && ptr->coef>=0)
            printf(" + ");
    }
    printf("\n");
}
int main(){
    int n,c,p,i;
    printf("Enter num of terms in first polynomial: ");
    scanf("%d",&n);
    for(i=0; i<n; i++){
        printf("Enter coef and pow: ");
        scanf("%d%d",&c,&p);
        list1 = create(list1, c, p);
    }
    printf("Enter num of terms in second polynomial: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        printf("Enter coef and power: ");
        scanf("%d%d",&c,&p);
        list2 = create(list2,c,p);
    }
    printf("First polynomial: ");
    display(list1);
    printf("Second poly: ");
    display(list2);
    list3 = add(list1, list2);
    printf("Result: ");
    display(list3);
    return 0;
}