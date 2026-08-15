#include <stdio.h>
#include <stdlib.h>
void selSort(int *arr, int n, int start) {
    if (start >= n - 1)
        return;
    int i, minIdx = start;
    for (i = start + 1; i < n; i++) {
        if (*(arr + i) < *(arr + minIdx))
            minIdx = i;
    }
    int temp = *(arr + minIdx);
    *(arr + minIdx) = *(arr + start);
    *(arr + start) = temp;
    selSort(arr, n, start + 1);
}
int main() {
    int n, i;
    printf("Enter n: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter arr: ");
    for (i = 0; i < n; i++)
        scanf("%d", arr + i);
    selSort(arr, n, 0);
    printf("Sorted: ");
    for (i = 0; i < n; i++)
        printf("%d ", *(arr + i));
    printf("\n");
    free(arr);
    return 0;
}
