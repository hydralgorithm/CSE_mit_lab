#include <stdio.h>
#include <stdlib.h>
struct Node {
    int coeff, exp;
    struct Node *prev, *next;
};
struct Node *newNode(int c, int e) {
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->coeff = c;
    n->exp = e;
    n->prev = n->next = NULL;
    return n;
}
void insertDesc(struct Node **head, int c, int e) {
    if (!(*head) || e > (*head)->exp) {
        struct Node *n = newNode(c, e);
        n->next = *head;
        if (*head) (*head)->prev = n;
        *head = n;
        return;
    }
    struct Node *t = *head;
    while (t->next && t->next->exp > e)
        t = t->next;
    if (t->next && t->next->exp == e) {
        t->next->coeff += c;
        return;
    }
    struct Node *n = newNode(c, e);
    n->next = t->next;
    n->prev = t;
    if (t->next) t->next->prev = n;
    t->next = n;
}
struct Node *readPoly(int terms) {
    struct Node *head = NULL;
    int c, e, i;
    for (i = 0; i < terms; i++) {
        printf("coeff exp: ");
        scanf("%d %d", &c, &e);
        insertDesc(&head, c, e);
    }
    return head;
}
void display(struct Node *head) {
    if (!head) { printf("0\n"); return; }
    struct Node *t = head;
    while (t) {
        printf("%dx^%d", t->coeff, t->exp);
        if (t->next) printf(" + ");
        t = t->next;
    }
    printf("\n");
}
struct Node *addPoly(struct Node *p1, struct Node *p2) {
    struct Node *res = NULL;
    struct Node *t1 = p1, *t2 = p2;
    while (t1 && t2) {
        if (t1->exp > t2->exp) { insertDesc(&res, t1->coeff, t1->exp); t1 = t1->next; }
        else if (t2->exp > t1->exp) { insertDesc(&res, t2->coeff, t2->exp); t2 = t2->next; }
        else {
            int s = t1->coeff + t2->coeff;
            if (s != 0) insertDesc(&res, s, t1->exp);
            t1 = t1->next; t2 = t2->next;
        }
    }
    while (t1) { insertDesc(&res, t1->coeff, t1->exp); t1 = t1->next; }
    while (t2) { insertDesc(&res, t2->coeff, t2->exp); t2 = t2->next; }
    return res;
}
int main() {
    int t1, t2;
    printf("Terms in P1: ");
    scanf("%d", &t1);
    struct Node *p1 = readPoly(t1);
    printf("Terms in P2: ");
    scanf("%d", &t2);
    struct Node *p2 = readPoly(t2);
    struct Node *sum = addPoly(p1, p2);
    printf("P1: "); display(p1);
    printf("P2: "); display(p2);
    printf("Sum: "); display(sum);
    return 0;
}
