#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Patient {
    char name[50];
    int age, priority;
};
struct Node {
    struct Patient p;
    struct Node *next;
};
struct Node *front = NULL, *rear = NULL;
void enqueue(char *name, int age, int pri) {
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    strcpy(n->p.name, name);
    n->p.age = age;
    n->p.priority = pri;
    n->next = NULL;
    if (!rear) { front = rear = n; }
    else { rear->next = n; rear = n; }
    printf("Added %s\n", name);
}
void dequeue() {
    if (!front) { printf("Empty\n"); return; }
    printf("Serving: %s Age:%d Priority:%d\n", front->p.name, front->p.age, front->p.priority);
    struct Node *t = front;
    front = front->next;
    if (!front) rear = NULL;
    free(t);
}
void display() {
    struct Node *t = front;
    if (!t) { printf("Empty\n"); return; }
    printf("Name\t\tAge\tPriority\n");
    while (t) {
        printf("%s\t\t%d\t%d\n", t->p.name, t->p.age, t->p.priority);
        t = t->next;
    }
}
int main() {
    int ch, age, pri;
    char name[50];
    while (1) {
        printf("\n1.Add patient 2.Serve 3.Display 4.Exit\nChoice: ");
        scanf("%d", &ch);
        if (ch == 1) { printf("name age priority: "); scanf("%s %d %d", name, &age, &pri); enqueue(name, age, pri); }
        else if (ch == 2) dequeue();
        else if (ch == 3) display();
        else if (ch == 4) break;
        else printf("Invalid\n");
    }
    return 0;
}
