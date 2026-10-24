#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node *front = NULL, *rear = NULL;
void enqueue(int val) {
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = val; n->next = NULL;
    if (!rear) { front = rear = n; }
    else { rear->next = n; rear = n; }
    printf("Enqueued %d\n", val);
}
void dequeue() {
    if (!front) { printf("Empty\n"); return; }
    printf("Dequeued %d\n", front->data);
    struct Node *t = front;
    front = front->next;
    if (!front) rear = NULL;
    free(t);
}
void display() {
    struct Node *t = front;
    if (!t) { printf("Empty\n"); return; }
    printf("Queue: ");
    while (t) { printf("%d ", t->data); t = t->next; }
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
