#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *next;
};
struct Node *head = NULL;

void beginsert(){
    int data;
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter value: ");
    scanf("%d",&data);
    temp->info = data;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
    } else {
        temp->next = head;
        head = temp;
        printf("Node inserted!");
    }
}
void lastinsert(){
    int data;
    struct Node *temp, *curn;
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d",&data);
    temp->info = data;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
    } else{
        curn = head;
        while(curn->next != NULL){
            curn = curn->next;
        }
        curn->next = temp;
        printf("Node inserted!");
    }
}
void randominsert(){
    int data, loc;
    struct Node *temp, *curn;
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter value: ");
    scanf("%d",&data);
    printf("Enter loc: ");
    scanf("%d", &loc);
    temp->info = data;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
    } else {
        curn = head;
        for(int i=1; i<loc; i++){
            curn = curn->next;
            if(curn == NULL){
                printf("cant insert!");
                return;
            }
        }
        temp->next = curn->next;
        curn->next = temp;
        printf("Node inserted!");
    }
}
void deletion_front(){
    struct Node *ptr;
    if(head == NULL){
        printf("List empty!");
    } else{
        ptr = head;
        head = ptr->next;
        free(ptr);
        printf("Node deleted!");
    }
}
void deletion_rear(){
    struct Node *prev, *curn;
    if(head == NULL){
        printf("list empty!");
    } else if(head->next == NULL){
        head = NULL;
        free(head);
        printf("Only node deleted!");
    } else {
        curn = head;
        prev = curn;
        while(curn->next != NULL){
            prev = curn;
            curn = curn->next;
        }
        printf("Deleted element is %d",curn->info);
        free(curn);
        prev->next = NULL;
    }
}
void random_delete(){
    struct Node *prev, *curn;
    printf("Enter loc: ");
    int loc;
    scanf("%d",&loc);
    if(head == NULL){
        printf("Empty list!");
    } else if(loc == 1){
        curn = head;
        head = head->next;
        free(curn);
        printf("First node deleted!");
        return;
    } else {
        curn = head;
        for(int i=1; i<loc; i++){
            prev = curn;
            curn = curn->next;
            if(curn == NULL){
                printf("Cant delete!");
                return;
            }
            prev->next = curn->next; 
            free(curn);
            printf("deleted node at pos %d", loc);
        }
    }
}
void display(){
    struct Node *curn;
    if(head == NULL){
        printf("List is empty!");
    } else{
        curn = head;
        while(curn != NULL){
            printf("\t%d",curn->info);
            curn = curn->next;
        }
    }
}
int main(){
    while(1){
        printf("1.Insert front\n");
        printf("2.Insert rear\n");
        printf("3.Insert custom\n");
        printf("4.Delete front\n");
        printf("5.Delete rear\n");
        printf("6.Delete custom\n");
        printf("7.Display\n");
        printf("8.Exit\n");
        printf("Enter choice: ");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:
                beginsert();
                break;
            case 2:
                lastinsert();
                break;
            case 3:
                randominsert();
                break;
            case 4:
                deletion_front();
                break;
            case 5:
                deletion_rear();
                break;
            case 6:
                random_delete();
                break;
            case 7:
                display();
                break;
            case 8:
                printf("exiting...");
                return 0;
            default:
                printf("Invalid!");
        }
    }
}