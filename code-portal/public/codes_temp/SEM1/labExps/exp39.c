#include <stdio.h>
struct student{
    char name[25];
    long rollno;
    float marks[3];
    float total;
    float average;
};
int main(){
    struct student s[5];
    int i,j;
    for(i=0;i<5;i++){
        printf("Enter details of student %d\n",i+1);
        printf("Enter student name: ");
        scanf("%s",s[i].name);
        printf("Enter student roll number: ");
        scanf("%ld",&s[i].rollno);
        s[i].total=0;
        printf("Enter marks in 3 subjects:\n");
        for(j=0;j<3;j++){
            printf("Enter marks of subject %d: ",j+1);
            scanf("%f",&s[i].marks[j]);
            s[i].total+=s[i].marks[j];
        }
        s[i].average = s[i].total/3;
    }
    printf("\nName\tRoll no\tTotal\tAverage\n");
    for(i=0;i<5;i++){
        printf("%s\t%ld\t%.2f\t%.2f\n",s[i].name,s[i].rollno,s[i].total,s[i].average);
    }
    return 0;
}