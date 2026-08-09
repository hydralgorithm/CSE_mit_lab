#include <stdio.h>
int main() {
    int n, key, i, found = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter arr: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter key: ");
    scanf("%d", &key);
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Not found\n");
    return 0;
}
