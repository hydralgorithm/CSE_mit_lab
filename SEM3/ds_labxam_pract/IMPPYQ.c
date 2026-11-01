#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

typedef struct node *Nodeptr;

// Global head
Nodeptr head = NULL;

// Saved list pointers
Nodeptr original = NULL, even = NULL, odd = NULL;
Nodeptr third = NULL, sorted = NULL, result = NULL;

Nodeptr newNode(int x) {
    Nodeptr temp = malloc(sizeof(struct node));
    if (temp == NULL) exit(1);

    temp->data = x;
    temp->prev = temp->next = NULL;
    return temp;
}

void append(int x) {
    Nodeptr temp = newNode(x);

    if (head == NULL) {
        head = temp;
        return;
    }

    Nodeptr p = head;
    while (p->next != NULL)
        p = p->next;

    p->next = temp;
    temp->prev = p;
}

void readList() {
    int n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        append(x);
    }
}

void display() {
    Nodeptr p = head;

    if (p == NULL) {
        printf("Empty list\n");
        return;
    }

    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void sort() {
    if (head == NULL) return;

    int swapped;
    Nodeptr p;

    do {
        swapped = 0;
        p = head;

        while (p->next != NULL) {
            if (p->data > p->next->data) {
                int t = p->data;
                p->data = p->next->data;
                p->next->data = t;
                swapped = 1;
            }
            p = p->next;
        }
    } while (swapped);
}

void separate() {
    Nodeptr p = original;

    even = odd = NULL;

    while (p != NULL) {
        head = (p->data % 2 == 0) ? even : odd;
        append(p->data);

        if (p->data % 2 == 0)
            even = head;
        else
            odd = head;

        p = p->next;
    }

    head = even;
    sort();
    even = head;

    head = odd;
    sort();
    odd = head;
}

void merge() {
    Nodeptr a = even, b = odd;
    head = NULL;

    while (a != NULL && b != NULL) {
        if (a->data < b->data) {
            append(a->data);
            a = a->next;
        } else {
            append(b->data);
            b = b->next;
        }
    }

    while (a != NULL) {
        append(a->data);
        a = a->next;
    }

    while (b != NULL) {
        append(b->data);
        b = b->next;
    }

    sorted = head;
}

void unionList() {
    Nodeptr a = sorted, b = third;
    head = NULL;

    while (a != NULL && b != NULL) {
        int x;

        if (a->data < b->data) {
            x = a->data;
            a = a->next;
        } else if (a->data > b->data) {
            x = b->data;
            b = b->next;
        } else {
            x = a->data;
            a = a->next;
            b = b->next;
        }

        if (head == NULL || head->prev->data != x)
            append(x);
    }

    while (a != NULL) {
        int x = a->data;
        if (head == NULL || head->prev->data != x)
            append(x);
        a = a->next;
    }

    while (b != NULL) {
        int x = b->data;
        if (head == NULL || head->prev->data != x)
            append(x);
        b = b->next;
    }

    result = head;
}

void deleteAlternate() {
    Nodeptr p = head;

    while (p != NULL && p->next != NULL) {
        Nodeptr temp = p->next;
        p->next = temp->next;

        if (temp->next != NULL)
            temp->next->prev = p;

        free(temp);
        p = p->next;
    }
}

int main() {
    printf("Enter original list:\n");
    readList();
    original = head;

    printf("Original list: ");
    display();

    separate();

    head = even;
    printf("Even list: ");
    display();

    head = odd;
    printf("Odd list: ");
    display();

    merge();
    head = sorted;
    printf("Combined sorted list: ");
    display();

    head = NULL;
    printf("\nEnter third list:\n");
    readList();
    sort();
    third = head;

    printf("Third list: ");
    display();

    unionList();
    head = result;
    printf("Union: ");
    display();

    deleteAlternate();
    printf("After deleting alternate nodes: ");
    display();

    return 0;
}