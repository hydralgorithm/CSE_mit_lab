#include <stdio.h>
#define MAX 100
struct Student {
    char name[50];
    int roll;
    char grade[5];
};
void readStudents(struct Student arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Name roll grade of student %d: ", i + 1);
        scanf("%s %d %s", arr[i].name, &arr[i].roll, arr[i].grade);
    }
}
void displayStudents(struct Student arr[], int n) {
    int i;
    printf("Name\t\tRoll\tGrade\n");
    for (i = 0; i < n; i++)
        printf("%s\t\t%d\t%s\n", arr[i].name, arr[i].roll, arr[i].grade);
}
void sortByRoll(struct Student arr[], int n) {
    int i, j;
    struct Student temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].roll > arr[j + 1].roll) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main() {
    int n;
    struct Student arr[MAX];
    printf("Enter n: ");
    scanf("%d", &n);
    readStudents(arr, n);
    sortByRoll(arr, n);
    printf("Sorted by roll:\n");
    displayStudents(arr, n);
    return 0;
}
