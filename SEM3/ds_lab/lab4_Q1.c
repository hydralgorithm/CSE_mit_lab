#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node *head = NULL;
struct Node *newNode(int data) {
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->next = NULL;
    return n;
}
void traverse() {
    struct Node *t = head;
    if (!t) { printf("Empty\n"); return; }
    while (t) { printf("%d -> ", t->data); t = t->next; }
    printf("NULL\n");
}
void insertBefore(int val, int target) {
    struct Node *n = newNode(val);
    if (!head) { head = n; return; }
    if (head->data == target) { n->next = head; head = n; return; }
    struct Node *t = head;
    while (t->next && t->next->data != target)
        t = t->next;
    if (!t->next) { printf("%d not found\n", target); free(n); return; }
    n->next = t->next;
    t->next = n;
}
void insertAfter(int val, int target) {
    struct Node *t = head;
    while (t && t->data != target)
        t = t->next;
    if (!t) { printf("%d not found\n", target); return; }
    struct Node *n = newNode(val);
    n->next = t->next;
    t->next = n;
}
void deleteNode(int val) {
    if (!head) { printf("Empty\n"); return; }
    if (head->data == val) {
        struct Node *t = head;
        head = head->next;
        free(t);
        return;
    }
    struct Node *t = head;
    while (t->next && t->next->data != val)
        t = t->next;
    if (!t->next) { printf("%d not found\n", val); return; }
    struct Node *d = t->next;
    t->next = d->next;
    free(d);
}
void reverseList() {
    struct Node *prev = NULL, *curr = head, *next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    printf("Reversed\n");
}
void sortList() {
    struct Node *i, *j;
    int temp;
    if (!head) return;
    for (i = head; i->next; i = i->next)
        for (j = i->next; j; j = j->next)
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
    printf("Sorted\n");
}
void deleteAlternate() {
    if (!head) return;
    struct Node *curr = head->next, *prev = head;
    while (curr) {
        prev->next = curr->next;
        free(curr);
        prev = prev->next;
        curr = prev ? prev->next : NULL;
    }
    printf("Alternate nodes deleted\n");
}
void insertSorted(int val) {
    struct Node *n = newNode(val);
    if (!head || head->data >= val) { n->next = head; head = n; return; }
    struct Node *t = head;
    while (t->next && t->next->data < val)
        t = t->next;
    n->next = t->next;
    t->next = n;
}
int main() {
    int ch, val, target;
    while (1) {
        printf("\n1.Insert before 2.Insert after 3.Delete 4.Traverse 5.Reverse 6.Sort 7.Del alternate 8.Insert sorted 9.Exit\nChoice: ");
        scanf("%d", &ch);
        if (ch == 1) { printf("val target: "); scanf("%d %d", &val, &target); insertBefore(val, target); }
        else if (ch == 2) { printf("val target: "); scanf("%d %d", &val, &target); insertAfter(val, target); }
        else if (ch == 3) { printf("val: "); scanf("%d", &val); deleteNode(val); }
        else if (ch == 4) traverse();
        else if (ch == 5) reverseList();
        else if (ch == 6) sortList();
        else if (ch == 7) deleteAlternate();
        else if (ch == 8) { printf("val: "); scanf("%d", &val); insertSorted(val); }
        else if (ch == 9) break;
        else printf("Invalid\n");
    }
    return 0;
}
