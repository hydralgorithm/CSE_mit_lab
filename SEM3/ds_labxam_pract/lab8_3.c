#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *front = NULL, *rear = NULL;
void enqueue(int data){
    struct node *temp = malloc(sizeof(struct node));
    if(temp==NULL)
        return;
    temp->data = data;
    temp->next = NULL;
    if(front==NULL){
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
        
}
int dequeue(){
    if(front==NULL)
        return -1;
    struct node *temp = front;
    int x = temp->data;
    if(front->next==NULL)
        front = rear = NULL;
    else{
        front = temp->next;
    }
    free(temp);
    return x;
}
int peek(){
    if(front==NULL)
        return -1;
    return front->data;
}
void display(){
    if(front==NULL)
        return;
    struct node *temp=front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    printf("%d\n",peek());
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());
    display();
    return 0;
}