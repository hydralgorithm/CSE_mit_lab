#include <stdio.h>
struct Student{
    char name[50];
    long rollno;
    float mark[3];
    float total;
    float avg; 
};
int main(){
    struct Student s[5];
    int i,j;
    for(i=0;i<5;i++){
        printf("Enter details of student %d :\n",i+1);
        printf("Student Name: ");
        scanf("%s",s[i].name);
        printf("Roll number: ");
        scanf("%ld",&s[i].rollno);
        s[i].total = 0;
        for(j=0;j<3;j++){
            printf("Mark%d : ",j+1);
            scanf("%f",&s[i].mark[j]);
            s[i].total+=s[i].mark[j];
        }
        s[i].avg = s[i].total/3; 
    }
    printf("\n____________________________________\n");
    printf("Name\tRoll no\tTotal\tAverage");
    printf("\n------------------------------------\n");
    for(i=0;i<5;i++){
        printf("%s\t%ld\t%.2f\t%.2f\n",s[i].name,s[i].rollno,s[i].total,s[i].avg);
    }
    return 0;
}