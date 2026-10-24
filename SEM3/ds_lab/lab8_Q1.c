#include <stdio.h>
#include <string.h>
#define MAX 10
struct Job {
    int id;
    char name[50];
};
struct Job queue[MAX];
int front = 0, rear = 0, count = 0;
void enqueue(int id, char *name) {
    if (count == MAX) { printf("Full\n"); return; }
    queue[rear].id = id;
    strcpy(queue[rear].name, name);
    rear = (rear + 1) % MAX;
    count++;
    printf("Enqueued: ID=%d %s\n", id, name);
}
void dequeue() {
    if (count == 0) { printf("Empty\n"); return; }
    printf("Printing: ID=%d %s\n", queue[front].id, queue[front].name);
    front = (front + 1) % MAX;
    count--;
}
void display() {
    if (count == 0) { printf("Empty\n"); return; }
    int i, j = front;
    printf("Queue: ");
    for (i = 0; i < count; i++) {
        printf("[%d:%s] ", queue[j].id, queue[j].name);
        j = (j + 1) % MAX;
    }
    printf("\n");
}
int main() {
    int ch, id;
    char name[50];
    while (1) {
        printf("\n1.Add job 2.Print job 3.Display 4.Exit\nChoice: ");
        scanf("%d", &ch);
        if (ch == 1) { printf("id name: "); scanf("%d %s", &id, name); enqueue(id, name); }
        else if (ch == 2) dequeue();
        else if (ch == 3) display();
        else if (ch == 4) break;
        else printf("Invalid\n");
    }
    return 0;
}
