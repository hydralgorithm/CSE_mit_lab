#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node *first = NULL, *last = NULL;
struct Node *newNode(int data) {
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->next = NULL;
    return n;
}
void insertEnd(int val) {
    struct Node *n = newNode(val);
    if (!first) {
        first = last = n;
        n->next = first;
        return;
    }
    last->next = n;
    n->next = first;
    last = n;
}
void deleteBegin() {
    if (!first) { printf("Empty\n"); return; }
    printf("Deleted %d\n", first->data);
    if (first == last) { free(first); first = last = NULL; return; }
    struct Node *t = first;
    first = first->next;
    last->next = first;
    free(t);
}
void display() {
    if (!first) { printf("Empty\n"); return; }
    struct Node *t = first;
    do { printf("%d -> ", t->data); t = t->next; } while (t != first);
    printf("(back to %d)\n", first->data);
}
int main() {
    int ch, val;
    while (1) {
        printf("\n1.Insert end 2.Delete begin 3.Display 4.Exit\nChoice: ");
        scanf("%d", &ch);
        if (ch == 1) { printf("val: "); scanf("%d", &val); insertEnd(val); display(); }
        else if (ch == 2) { deleteBegin(); display(); }
        else if (ch == 3) display();
        else if (ch == 4) break;
        else printf("Invalid\n");
    }
    return 0;
}
