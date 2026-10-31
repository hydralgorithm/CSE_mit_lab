#include <stdio.h>
#define MAX 5
struct Queue{
    int items[MAX];
    int front,rear;
};
void init(struct Queue *q){
    q->front = q->rear = -1;
}
void enqueue(struct Queue *q, int data){
    if((q->rear+1)%MAX==q->front){
        printf("Full!\n");
        return;
    }
    if(q->front == q->rear)
        q->front = 0;
    q->rear = (q->rear+1)%MAX;
    q->items[q->rear] = data;
    printf("Inserted!\n");
}
int dequeue(struct Queue *q){
    if(q->front==-1){
        printf("Empty!\n");
        return -1;
    }
    int x = q->items[q->front];
    if(q->front==q->rear){
        q->front = q->rear = -1;
    }else{
        q->front = (q->front+1)%MAX;
    }
    return x;
}
void display(struct Queue *q){
    if(q->front==-1)
        return;
    int i=q->front;
    while(1){
        printf("%d ",q->items[i]);
        if(i==q->rear)
            break;
        i = (i+1)%MAX;
    }
    printf("\n");
}
int main(){
    struct Queue q;
    init(&q);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    display(&q);
    printf("%d",dequeue(&q));
    printf("%d",dequeue(&q));
    return 0;
}