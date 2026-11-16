#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct node{
    int songID;
    int duration;
    char title[50];
    struct node *next;
} Node;
Node* insertSong(Node *head, int songID, char title[], int duration){
    Node *temp = malloc(sizeof(struct node));
    temp->songID = songID;
    temp->duration = duration;
    strcpy(temp->title,title);
    temp->next = NULL;
    if(head==NULL){
        return temp;
    }
    Node *curn = head;
    while(curn->next!=NULL){
        curn = curn->next;
    }
    curn->next = temp;
    return head;
}
Node *removeShortSongs(Node *head,int limit){
    Node *curn = head, *parent = NULL;
    if(head==NULL)
        return head;
    while(curn!=NULL){
        parent = curn;
        if(curn->duration<limit){
            Node *temp=curn;
            if(parent == NULL)
                head = curn->next;
            else
                parent->next = curn->next;
            free(temp);
        }
        curn = curn->next;
    }
    return head;
}
void displayPlaylist(Node *head){
    Node *curn = head;
    while(curn!=NULL){
        printf("%s ->",curn->title);
        curn = curn->next;
    }
    printf("NULL");
}
