#include <stdio.h>
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main() {
    int n, key, i;
    printf("Enter n: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter sorted arr: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter key: ");
    scanf("%d", &key);
    int pos = binarySearch(arr, n, key);
    if (pos != -1)
        printf("Found at position %d\n", pos + 1);
    else
        printf("Not found\n");
    return 0;
}
