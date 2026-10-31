#include <stdio.h>
#define MAX 5
struct Queue{
    int items[MAX];
    int front,rear;
};
void init(struct Queue *q){
    q->rear = q->front = -1;
};
void enqueue(struct Queue *q, int data){
    if(q->rear==MAX-1){
        printf("FULL!\n");
        return;
    }
    if(q->front==-1)
        q->front=0;
    q->items[++q->rear] = data;
    printf("Enqueued\n");
}
int dequeue(struct Queue *q){
    if(q->front==-1)
        return -1;
    int val = q->items[q->front];
    if(q->front==q->rear)
        q->front=q->rear=-1;
    else
        q->front++;
    return val;
}
void display(struct Queue *q){
    if(q->front==-1)
        return;
    for(int i=q->front; i<=q->rear; i++){
        printf("%d ",q->items[i]);
    }
    printf("\n");
}
int peek(struct Queue *q){
    if(q->front==-1)
        return -1;
    return q->items[q->front];
}
int main(){
    struct Queue q;
    init(&q);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    printf("%d",dequeue(&q));
    printf("%d",peek(&q));
    display(&q);
    return 0;
}
