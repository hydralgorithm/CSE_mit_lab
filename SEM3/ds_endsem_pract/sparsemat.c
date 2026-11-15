
typedef struct {
    int row, col, value;
} SM;

void fastTranspose(SM a[], SM b[]) {
    int row_terms[100] = {0};
    int starting_pos[100];

    int n = a[0].value;
    int cols = a[0].col;

    // Transpose header
    b[0].row = cols;
    b[0].col = a[0].row;
    b[0].value = n;

    // Count entries in each original column
    for (int i = 1; i <= n; i++)
        row_terms[a[i].col]++;

    // Find starting position of each new row
    starting_pos[0] = 1;
    for (int i = 1; i < cols; i++)
        starting_pos[i] =
            starting_pos[i-1] + row_terms[i-1];

    // Swap coordinates and place each triplet
    for (int i = 1; i <= n; i++) {
        int j = starting_pos[a[i].col]++;

        b[j].row = a[i].col;
        b[j].col = a[i].row;
        b[j].value = a[i].value;
    }
}
