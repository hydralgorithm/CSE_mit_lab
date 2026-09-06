#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *head1 = NULL, *tail1 = NULL;
struct Node *head2 = NULL, *tail2 = NULL;
struct Node *newNode(int data) {
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->prev = n->next = NULL;
    return n;
}
void insertRear(struct Node **head, struct Node **tail, int val) {
    struct Node *n = newNode(val);
    if (!(*head)) { *head = *tail = n; return; }
    (*tail)->next = n;
    n->prev = *tail;
    *tail = n;
}
void display(struct Node *head) {
    struct Node *t = head;
    if (!t) { printf("Empty\n"); return; }
    while (t) { printf("%d ", t->data); t = t->next; }
    printf("\n");
}
void concatenate() {
    if (!head1) { head1 = head2; tail1 = tail2; }
    else if (head2) {
        tail1->next = head2;
        head2->prev = tail1;
        tail1 = tail2;
    }
    head2 = tail2 = NULL;
    printf("X1 after concat: ");
    display(head1);
}
int main() {
    int n, val, i;
    printf("Enter n for X1: ");
    scanf("%d", &n);
    printf("Enter X1: ");
    for (i = 0; i < n; i++) { scanf("%d", &val); insertRear(&head1, &tail1, val); }
    printf("Enter n for X2: ");
    scanf("%d", &n);
    printf("Enter X2: ");
    for (i = 0; i < n; i++) { scanf("%d", &val); insertRear(&head2, &tail2, val); }
    printf("X1: "); display(head1);
    printf("X2: "); display(head2);
    concatenate();
    return 0;
}
