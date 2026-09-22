#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node *top = NULL;
void push(int val){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if(!newNode){
        printf("Stack Overflow!\n");
        return;
    }
    newNode->data = val;
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack!\n",val);
}
void pop(){
    if(top == NULL){
        printf("Stack Underflow!\n");
        return;
    }
    struct Node *temp = top;
    printf("%d popped out!\n",top->data);
    top = top->next;
    free(temp);
}
void peek(){
    if(top==NULL){
        printf("Empty stack!\n");
        return;
    }
    printf("Top ele: %d\n",top->data);
}
int isEmpty(){
    return (top == NULL);
}
void display(){
    struct Node *temp = top;
    if(temp == NULL){
        printf("Empty stack!\n");
        return;
    }
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    int ch, val;
    while(1){
        printf("\n1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(val);  break;
            case 2:
                pop();  break;
            case 3:
                peek(); break;
            case 4:
                if (isEmpty())
                    printf("Stack is empty\n");
                else
                    printf("Stack is not empty\n");   break;
            case 5:
                display(); break;
            case 6:
                exit(0);
            default:
                printf("Invalide!\n");
        }
            
    }
    return 0;
}