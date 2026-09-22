#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *head = NULL;
struct Node * createNode(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void insertFront(int data){
    struct Node *newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}
void insertRear(int data){
    struct Node *newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
void insertAtPos(int data, int pos){
    struct Node *newNode = createNode(data);
    if(pos == 1){
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }
    struct Node *temp = head;
    for(int i=1; temp!=NULL && i<pos-1; i++)
        temp = temp->next;
    
    if(temp == NULL){
        printf("Pos out of range!");
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if(temp->next!=NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
}
void deleteFront(){
    if(head == NULL){
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    if(head != NULL)
        head->prev = NULL;
    free(temp);
}
void deleteRear(){
    if(head == NULL){
        printf("Empty list!");
        return;
    }
    struct Node *temp = head;
    if(temp->next == NULL){
        head == NULL;
        free(temp);
        return;
    }
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}
void deleteNode(int key){
    struct Node *temp = head;
    while(temp!=NULL && temp->data!=key){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Node not found!");
        return;
    }
    if(temp->prev != NULL){
        temp->prev->next = temp->next;
    } else{
        head = temp->next;
    }
    if(temp->next!=NULL){
        temp->next->prev = temp->prev;        
    }
    free(temp);
}
void display(){
    struct Node *temp = head;
    if(head == NULL){
        printf("List is empty!");
        return;
    }
    while(temp!=NULL){
        printf("%d <-> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main(){
    insertFront(10);
    insertRear(20);
    insertRear(30);
    insertAtPos(15,2);
    display();
    deleteFront();
    display();
    deleteRear();
    display();
    deleteNode(20);
    display();
    return 0;
}