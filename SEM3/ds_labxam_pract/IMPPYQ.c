#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev, *next;
} *Nodeptr;

Nodeptr head = NULL;
Nodeptr original, even, odd, sorted, third;

void insert(int x) {
    Nodeptr p = (Nodeptr)malloc(sizeof(struct node));
    p->data = x;
    p->next = NULL;
    p->prev = NULL;

    if (head == NULL)
        head = p;
    else {
        Nodeptr t = head;
        while (t->next != NULL)
            t = t->next;
        t->next = p;
        p->prev = t;
    }
}

void display(Nodeptr p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void sort() {
    Nodeptr i, j;
    int temp;

    for (i = head; i != NULL; i = i->next)
        for (j = i->next; j != NULL; j = j->next)
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
}

void removeDuplicates() {
    Nodeptr p = head, q;

    while (p != NULL && p->next != NULL) {
        if (p->data == p->next->data) {
            q = p->next;
            p->next = q->next;
            if (q->next != NULL)
                q->next->prev = p;
            free(q);
        } else
            p = p->next;
    }
}

void deleteAlternate() {
    Nodeptr p = head, q;

    while (p != NULL && p->next != NULL) {
        q = p->next;
        p->next = q->next;

        if (q->next != NULL)
            q->next->prev = p;

        free(q);
        p = p->next;
    }
}

int main() {
    int n, x, i;
    Nodeptr p;

    // Original list
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        insert(x);
    }

    original = head;
    printf("Original list: ");
    display(original);

    // Separate even and odd elements
    head = NULL;
    p = original;

    while (p != NULL) {
        if (p->data % 2 == 0) {
            head = even;
            insert(p->data);
            even = head;
        } else {
            head = odd;
            insert(p->data);
            odd = head;
        }
        p = p->next;
    }

    // Sort even and odd lists
    head = even;
    sort();
    even = head;

    head = odd;
    sort();
    odd = head;

    printf("Even list: ");
    display(even);

    printf("Odd list: ");
    display(odd);

    // Combine both sorted lists
    head = NULL;

    p = even;
    while (p != NULL) {
        insert(p->data);
        p = p->next;
    }

    p = odd;
    while (p != NULL) {
        insert(p->data);
        p = p->next;
    }

    sort();
    sorted = head;

    printf("Sorted list: ");
    display(sorted);

    // Read third list
    head = NULL;

    printf("Enter number of elements in third list: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        insert(x);
    }

    third = head;

    // Union of sorted and third list
    head = sorted;

    p = third;
    while (p != NULL) {
        insert(p->data);
        p = p->next;
    }

    sort();
    removeDuplicates();

    printf("Union: ");
    display(head);

    // Delete alternate nodes
    deleteAlternate();

    printf("After deleting alternate nodes: ");
    display(head);

    return 0;
}