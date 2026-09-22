#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct Node{
    char song[50];
    struct Node *next;
};
struct Node *head = NULL;

void begInsert(char *songName){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    strcpy(temp->song,songName);
    temp->next = NULL;
    if(head == NULL){
        head = temp;
    } else{
        temp->next = head;
        head = temp;
    }
}
void insertAfter(char *givenSong, char *newSong){
    struct Node *curn = head;
    while(curn!=NULL && strcmp(curn->song,givenSong)!=0){
        curn = curn->next;
    }
    if(curn == NULL){
        printf("Song not found!\n");
        return;
    }
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    strcpy(temp->song, newSong);
    temp->next = curn->next;
    curn->next = temp;
}
void deleteSong(char *songName){
    struct Node *curn = head, *prev = NULL;
    if(head == NULL){
        printf("Empty playlist!\n");
        return;
    }
    if(strcmp(head->song,songName)==0){
        curn = head;
        head = head->next;
        free(curn);
        return;
    }
    while(curn!=NULL && strcmp(curn->song,songName)!=0){
        prev = curn;
        curn = curn->next;
    }
    if(curn == NULL){
        printf("Song not found!\n");
        return;
    }
    prev->next = curn->next;
    free(curn);
}
void display(){
    struct Node *temp = head;
    while(temp!=NULL){
        printf("%s ->",temp->song);
        temp = temp->next;
    }
    printf(" NULL\n");
}
int main(){
    begInsert("Jojo");
    begInsert("Vladmir");
    begInsert("TameImpala");
    begInsert("RadioHead");
    display();
    deleteSong("TameImpala");
    display();
    return 0;
}