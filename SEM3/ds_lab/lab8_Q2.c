#include <stdio.h>
#define MAX 10
int queue[MAX];
int front = -1, rear = -1;
void enqueue(int val) {
    if ((rear + 1) % MAX == front) { printf("Full\n"); return; }
    if (front == -1) front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = val;
    printf("Enqueued %d\n", val);
}
void dequeue() {
    if (front == -1) { printf("Empty\n"); return; }
    printf("Dequeued %d\n", queue[front]);
    if (front == rear) { front = rear = -1; return; }
    front = (front + 1) % MAX;
}
void display() {
    if (front == -1) { printf("Empty\n"); return; }
    int i = front;
    printf("Queue: ");
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
int main() {
    int ch, val;
    while (1) {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\nChoice: ");
        scanf("%d", &ch);
        if (ch == 1) { printf("val: "); scanf("%d", &val); enqueue(val); }
        else if (ch == 2) dequeue();
        else if (ch == 3) display();
        else if (ch == 4) break;
        else printf("Invalid\n");
    }
    return 0;
}
