#include <stdio.h>
#include <stdlib.h>
struct Student {
    char name[50];
    int roll;
    float marks;
};
void readStudents(struct Student *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Name roll marks of student %d: ", i + 1);
        scanf("%s %d %f", (arr + i)->name, &(arr + i)->roll, &(arr + i)->marks);
    }
}
void displayStudents(struct Student *arr, int n) {
    int i;
    printf("Name\t\tRoll\tMarks\n");
    for (i = 0; i < n; i++)
        printf("%s\t\t%d\t%.2f\n", (arr + i)->name, (arr + i)->roll, (arr + i)->marks);
}
void findHighest(struct Student *arr, int n) {
    int i, idx = 0;
    for (i = 1; i < n; i++) {
        if ((arr + i)->marks > (arr + idx)->marks)
            idx = i;
    }
    printf("Highest: %s, Roll: %d, Marks: %.2f\n", (arr + idx)->name, (arr + idx)->roll, (arr + idx)->marks);
}
int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    struct Student *arr = (struct Student *)malloc(n * sizeof(struct Student));
    readStudents(arr, n);
    displayStudents(arr, n);
    findHighest(arr, n);
    free(arr);
    return 0;
}
