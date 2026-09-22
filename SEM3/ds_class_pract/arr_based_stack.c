#include <stdio.h>

#define MAX 5
int stack[MAX], top = -1;

void push(int item){
    if(top == MAX-1){
        printf("Stack Overflow!\n");
    } else {
        stack[++top] = item;
        printf("%d pushed to stack!\n",item);
    }
}
void pop(){
    if(top==-1){
        printf("Stack Underflow!\n");
    } else {
        printf("Popped: %d\n",stack[top--]);
    }
}
void peek(){
    if(top == -1){
        printf("Empty stack!\n");
    } else{
        printf("Top: %d\n",stack[top]);
    }
}
void isFull(){
    if(top == MAX-1)
        printf("Stack full!\n");
    else
        printf("Stack not full!\n");
}
void isEmpty(){
    if(top == -1)
        printf("Empty stack!\n");
    else
        printf("Not empty stack!\n");
}
void display(){
    if(top == -1){
        printf("Empty stack!");
    } else{
        for(int i=top; i>=0; i--){
            printf("%d ",stack[i]);
        }
        printf("\n");
    }
}
int main(){
    int choice, item;
    while(1){
        printf("\n1.Push\n2.Pop\n3.Peek\n4.isFull\n5.isEmpty\n6.Display\n7.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("enter item: ");
                scanf("%d",&item);
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                isFull();
                break;
            case 5:
                isEmpty();
                break;
            case 6:
                display(); break;
            case 7: 
                printf("Exiting...");
                return 0;
            default:
                printf("Invalid!");
        }
    }
}
