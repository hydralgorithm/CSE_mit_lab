#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct node{
    char process[10];
    struct node *next;
};
struct node *head = NULL;
struct node *createNode(char *p){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    strcpy(newNode->process,p);
    newNode->next=NULL;
    return newNode;
}
void insertRear(char *p){
    struct node *newNode = createNode(p);
    if(head==NULL){
        head = newNode;
        newNode->next = head;
        return;
    }
    struct node *temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next =newNode;
    newNode->next = head;
};
// void deleteNode(char *key){
//     struct node *temp = head, *prev=NULL;
//     if(head == NULL){
//         printf("Empty!\n");
//         return;
//     }
//     if(strcmp(head->process,key)==0){
//         if(head->next==head){
//             free(head);
//             head==NULL;
//             return;
//         }
//         struct node
//         head = head->next;
//         free(head);
//     }
    
//     while(temp->)
// }