#include <stdio.h>
#include <stdlib.h>

typedef struct Patient{
    int id;
    char name[50];
    struct Patient *next, *prev;
} Patient;
Patient *front = NULL, *rear = NULL;
void registerPatient(int id, char name[]){
    Patient  *temp = malloc(sizeof(Patient));
    temp->id = id;
    strcpy(temp->name,name);
    temp->next = NULL;
    if(front == NULL)
        front = temp;        
    else
        rear->next = temp;
    rear = temp;
}
void servePatient(){
    if(front==NULL)
        return;
    Patient *temp = front;
    printf("Served: %s\n",temp->name);
    front = front->next;
    if(front==NULL)
        rear==NULL;
    else{
        front->prev = NULL;
    }
    free(temp);
}
void removePatient(int id){
    Patient *temp = front;
    while(temp!=NULL && temp->id!=id)
        temp = temp->next;
    if(temp==NULL)
        return;
    if(temp->prev==NULL){
        front = temp->next;
    } else
        temp->prev->next = temp->next;
    if(temp->next == NULL)
        rear = temp->prev;
    else
        temp->next->prev = temp->prev;
    free(temp);
}
// void display()