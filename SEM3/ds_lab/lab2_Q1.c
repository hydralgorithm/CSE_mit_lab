#include <stdio.h>
#include <stdlib.h>
int findSmallest(int *arr, int n) {
    int i, min = *arr;
    for (i = 1; i < n; i++) {
        if (*(arr + i) < min)
            min = *(arr + i);
    }
    return min;
}
int main() {
    int n, i;
    printf("Enter n: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter arr: ");
    for (i = 0; i < n; i++)
        scanf("%d", arr + i);
    printf("Smallest: %d\n", findSmallest(arr, n));
    free(arr);
    return 0;
}
