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
void insertAfter(int data, int ele){
    if(head==NULL){
        printf("Empty\n");
        return;
    }
    struct node *curn;
    curn=head;
    while(curn!=NULL){
        if(curn->data == ele){
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            temp->data = data;
            temp->next = NULL;
            temp->next = curn->next;
            curn->next = temp;
            printf("Inserted");
            return;
        }
        curn=curn->next;
    }
    printf("Ele doesnt exist\n");
}
void insertBefore(int data, int ele){
    if(head==NULL){
        printf("Empty\n");
        return;
    }
    if(head->data==ele){
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp->data = data;
        temp->next = head;
        head=temp;
        printf("Inserted\n");
        return;
    }
    struct node *curn,*prev;
    curn=head;
    prev=NULL;
    while(curn!=NULL){
        if(curn->data==ele){
            struct node *temp = (struct node*)malloc(sizeof(struct node));
            temp->data = data;
            temp->next = curn;
            prev->next = temp;
            printf("Inserted!\n");
            return;
        }
        prev = curn;
        curn = curn->next;
    }
    printf("Ele doesnt exist!\n");
}
void travFor(){
    struct node *curn = head;
    printf("Traverse:\n");
    while(curn!=NULL){
        printf("%d -> ",curn->data);
        curn = curn->next;
    }
    printf("NULL\n");
}
void revTrav(){
    struct node *prev = NULL, *curn=head, *next=NULL;
    while(curn!=NULL){
        next = curn->next;
        curn->next = prev;
        prev = curn;
        curn=next;
    }
    head=prev;
    travFor();
}
int main(){
    while(1){
        printf("\n1.End insert\n2.End delete\n3.Insert pos\n4.Delete pos\n5.Insert after\n6.Insert before\n7.Traverse fwd\n8.Traverse backward\n9.Exit\nEnter choice: ");
        int ch, data, pos, ele;
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter ele: ");
                scanf("%d",&data);
                lastInsert(data);
                break;
            case 2:
                lastDelete();
                break;
            case 3:
                printf("Data and pos: ");
                scanf("%d%d",&data,&pos);
                insertPos(data,pos);
                break;
            case 4:
                printf("Enter pos: ");
                scanf("%d",&pos);
                delPos(pos);
                break;
            case 5:
                printf("Enter data and ele: ");
                scanf("%d%d",&data,&ele);
                insertAfter(data,ele);
                break;
            case 6:
                printf("Enter data and ele: ");
                scanf("%d%d",&data,&ele);
                insertBefore(data,ele);
                break;
            case 7:
                travFor();
                break;
            case 8:
                revTrav();
                break;
            case 9:
                return 0;
            default:
                printf("Invalid!\n");
        }
    }
    return 0;
}