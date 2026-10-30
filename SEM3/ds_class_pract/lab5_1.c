#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;
void lastInsert(int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if(head==NULL){
        printf("Inserted!\n");
        head = temp;
        return;
    }    
    struct node *curn;
    curn = head;
    while(curn->next != NULL){
        curn = curn->next;
    }
    curn->next = temp;
    printf("Inserted!\n");
}
void lastDelete(){
    struct node *curn, *prev;
    if(head==NULL){
        printf("Empty list!\n");
        return;
    }
    if(head->next == NULL){
        free(head);
        head = NULL;
        printf("Only 1 node, so deleted\n");
        return;
    }
    curn = head;
    prev = curn;
    while(curn->next!=NULL){
        prev = curn;
        curn=curn->next;
    }
    free(curn);
    prev->next = NULL;
    printf("Last node deleted!\n");
}
void insertPos(int data, int pos){
    struct node *temp, *curn; 
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if(pos<1){
        printf("Exit!\n");
        free(temp);
        temp = NULL;
        return;
    }
    if(pos == 1){
        temp->next = head;
        head = temp;
        printf("Inserted!\n");
        return;
    }
    curn = head;
    for(int i=1; i<pos-1; i++){
        curn = curn->next;
        if(curn==NULL){
            printf("NULL\n");
            free(temp);
            temp=NULL;
            return;
        }
    }
    temp->next = curn->next;
    curn->next = temp;
    printf("Inserted!\n");
}
void delPos(int pos){
    if(head==NULL){
        printf("Empty!\n");
        return;
    }
    struct node *curn = head;
    if(pos==1){
        head = curn->next;
        free(curn);
        printf("Deleted!\n");
        return;
    }
    struct node *prev = NULL;
    for(int i=1;i<pos;i++){
        prev = curn;
        curn = curn->next;
        if(curn == NULL){
            printf("Not exist!\n");
            return;
        }
    }
    prev->next = curn->next;
    free(curn);
    printf("Deleted!");
}