#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char tab[50];
    struct node *prev;
    struct node *next;
};
struct node *head = NULL;
struct node *current = NULL;

struct node *createNode(char *tab){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    strcpy(newNode->tab,tab);
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void addWebpage(char *tab){
    struct node *newNode = createNode(tab);
    if(head==NULL){
        head = newNode;
        current = newNode;
    } 
    struct node *temp;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    current = newNode;
}
void moveBackward(){
    if(current!=NULL && current->prev != NULL){
        current = current->prev;
    } else{
        printf("No previous page!\n");
    }
}
void moveForward(){
    if(current!=NULL && current->next!=NULL){
        current = current->next;
    } else{
        printf("Next page doesnt exist!\n");
    }
}
void deletePage(char *tab){
    struct node *curn=head, *behind=NULL;
    if(head == NULL){
        printf("Empty tabs!\n");
        return;
    }
    if(strcmp(head->tab,tab)==0){
        head = head->next;
        if(head!=NULL)
            head->prev = NULL;
        free(curn);
        return;
    }
    while(curn!=NULL && strcmp(curn->tab, tab)!=0){
        behind = curn;
        curn=curn->next;
    }
    if(curn == NULL){
        printf("ele doesnt exist!\n");
        return;
    }
    behind->next = curn->next;
    curn->next->prev = behind;
    free(curn);
}