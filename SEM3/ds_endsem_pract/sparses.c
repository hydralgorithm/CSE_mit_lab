
#include <stdio.h>
#include <stdlib.h>

// For simple and fast transpose
typedef struct {
    int row, col, value;
} SM;

// For linked-list transpose
struct Node {
    int row, col, value;
    struct Node *next;
};



void simpleTranspose(SM a[], SM b[]) {
    int k = 1;

    // Copy header and swap dimensions
    b[0] = a[0];
    b[0].row = a[0].col;
    b[0].col = a[0].row;

    // Check each original column
    for (int c = 0; c < a[0].col; c++) {
        for (int i = 1; i <= a[0].value; i++) {
            if (a[i].col == c) {
                b[k].row = a[i].col;
                b[k].col = a[i].row;
                b[k].value = a[i].value;
                k++;
            }
        }
    }
}



void fastTranspose(SM a[], SM b[]) {
    int row_terms[100] = {0};
    int starting_pos[100];

    int n = a[0].value;
    int cols = a[0].col;

    // Transpose header
    b[0].row = cols;
    b[0].col = a[0].row;
    b[0].value = n;

    // Count elements in each column
    for (int i = 1; i <= n; i++)
        row_terms[a[i].col]++;

    // Calculate starting positions
    starting_pos[0] = 1;

    for (int i = 1; i < cols; i++)
        starting_pos[i] =
            starting_pos[i-1] + row_terms[i-1];

    // Place transposed elements
    for (int i = 1; i <= n; i++) {
        int j = starting_pos[a[i].col]++;

        b[j].row = a[i].col;
        b[j].col = a[i].row;
        b[j].value = a[i].value;
    }
}


struct Node* linkedTranspose(struct Node *head, int cols) {
    struct Node *result = NULL;
    struct Node *tail = NULL;

    // Check each original column
    for (int c = 0; c < cols; c++) {
        struct Node *temp = head;

        while (temp != NULL) {
            if (temp->col == c) {
                struct Node *n = malloc(sizeof(struct Node));

                // Swap row and column
                n->row = temp->col;
                n->col = temp->row;
                n->value = temp->value;
                n->next = NULL;

                // Attach node to result
                if (result == NULL)
                    result = n;
                else
                    tail->next = n;

                tail = n;
            }

            temp = temp->next;
        }
    }

    return result;
}
