#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *head = NULL, *tail = NULL;
struct Node *newNode(int data) {
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->prev = n->next = NULL;
    return n;
}
void insertRear(int val) {
    struct Node *n = newNode(val);
    if (!head) { head = tail = n; return; }
    tail->next = n;
    n->prev = tail;
    tail = n;
}
void deleteRear() {
    if (!tail) { printf("Empty\n"); return; }
    printf("Deleted %d\n", tail->data);
    if (head == tail) { free(tail); head = tail = NULL; return; }
    struct Node *t = tail;
    tail = tail->prev;
    tail->next = NULL;
    free(t);
}
void insertAtPos(int val, int pos) {
    struct Node *n = newNode(val);
    if (pos == 1) {
        if (!head) { head = tail = n; return; }
        n->next = head;
        head->prev = n;
        head = n;
        return;
    }
    struct Node *t = head;
    int i;
    for (i = 1; i < pos - 1 && t; i++)
        t = t->next;
    if (!t) { printf("Out of range\n"); free(n); return; }
    n->next = t->next;
    n->prev = t;
    if (t->next) t->next->prev = n;
    else tail = n;
    t->next = n;
}
void deleteAtPos(int pos) {
    if (!head) { printf("Empty\n"); return; }
    struct Node *t = head;
    int i;
    for (i = 1; i < pos && t; i++)
        t = t->next;
    if (!t) { printf("Out of range\n"); return; }
    printf("Deleted %d\n", t->data);
    if (t->prev) t->prev->next = t->next;
    else head = t->next;
    if (t->next) t->next->prev = t->prev;
    else tail = t->prev;
    free(t);
}
void insertAfterVal(int val, int target) {
    struct Node *t = head;
    while (t && t->data != target) t = t->next;
    if (!t) { printf("%d not found\n", target); return; }
    struct Node *n = newNode(val);
    n->next = t->next;
    n->prev = t;
    if (t->next) t->next->prev = n;
    else tail = n;
    t->next = n;
}
void insertBeforeVal(int val, int target) {
    struct Node *t = head;
    while (t && t->data != target) t = t->next;
    if (!t) { printf("%d not found\n", target); return; }
    struct Node *n = newNode(val);
    n->next = t;
    n->prev = t->prev;
    if (t->prev) t->prev->next = n;
    else head = n;
    t->prev = n;
}
void traverseFwd() {
    struct Node *t = head;
    if (!t) { printf("Empty\n"); return; }
    printf("Fwd: ");
    while (t) { printf("%d ", t->data); t = t->next; }
    printf("\n");
}
void traverseRev() {
    struct Node *t = tail;
    if (!t) { printf("Empty\n"); return; }
    printf("Rev: ");
    while (t) { printf("%d ", t->data); t = t->prev; }
    printf("\n");
}
int main() {
    int ch, val, pos, target;
    while (1) {
        printf("\n1.Insert rear 2.Delete rear 3.Insert at pos 4.Delete at pos 5.Insert after 6.Insert before 7.Fwd traverse 8.Rev traverse 9.Exit\nChoice: ");
        scanf("%d", &ch);
        if (ch == 1) { printf("val: "); scanf("%d", &val); insertRear(val); }
        else if (ch == 2) deleteRear();
        else if (ch == 3) { printf("val pos: "); scanf("%d %d", &val, &pos); insertAtPos(val, pos); }
        else if (ch == 4) { printf("pos: "); scanf("%d", &pos); deleteAtPos(pos); }
        else if (ch == 5) { printf("val target: "); scanf("%d %d", &val, &target); insertAfterVal(val, target); }
        else if (ch == 6) { printf("val target: "); scanf("%d %d", &val, &target); insertBeforeVal(val, target); }
        else if (ch == 7) traverseFwd();
        else if (ch == 8) traverseRev();
        else if (ch == 9) break;
        else printf("Invalid\n");
    }
    return 0;
}
