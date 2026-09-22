#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;

struct node *createNode(int data){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertFront(int data){
    struct node *newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        newNode->next = head;
    } else{
        struct node *temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}
void insertEnd(int data){
    struct node *newNode = createNode(data);
    if(head==NULL){
        head = newNode;
        newNode->next = head;
    } else {
        struct node *temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}
void insertAtPosition(int data, int pos){
    struct node *newNode = createNode(data);
    if(pos == 1){
        insertFront(data);
        return;
    }
    struct node *temp = head;
    for(int i=1; i<pos-1 && temp->next!=head; i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteFront(){
    if(head == NULL){
        printf("Empty list!");
        return;
    }
    struct node *temp = head;
    if(head->next == head){
        head = NULL;
    } else{
        struct node *last = head;
        while(last->next != head){
            last = last->next;
        }
        head = head->next;
        last->next = head;
    }
    free(temp);
}
void deleteRear(){
    if(head == NULL){
        printf("Empty list!");
        return;
    }
    struct node *temp = head;
    if(head->next = head){
        head = NULL;
    } else {
        struct node *prev = NULL;
        while(temp->next != head){
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
    }
    free(temp);
}
void deleteNode(int key){
    if(head == NULL){
        printf("Empty list!");
        return;
    }
    struct node *temp = head, *prev = NULL;
    if(temp->data == key){
        if(temp->next == head){
            head = NULL;
            free(temp);
            return;
        }
        while(temp->next!=head){
            temp = temp->next;
        }
        temp->next = head->next;
        free(head);
        head = temp->next;
        return;
    }
    while(temp->next!=head && temp->data!=key){
        prev = temp;
        temp= temp->next;
    }
    if(temp->data == key){
        prev->next = temp->next;
        free(temp);
    } else {
        printf("Node with data %d not found!\n",key);
    }
}
void display(){
    if(head == NULL){
        printf("List is empty!");
        return;
    }
    struct node *temp = head;
    do{
        printf("%d -> ",temp->data);
        temp = temp->next;
    }while(temp != head);
    printf(" %d(head)\n",head->data);
}
int main(){
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);
    display();
    deleteNode(30);
    display();
}