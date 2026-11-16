#include <stdio.h>
struct Date{
    int day,month,year;
};
struct Student{
    char name[30];
    int rollno;
    struct Date dob;
};
int main(){
    struct Student s;
    scanf("%s%d",s.name,&s.rollno);
    scanf("%d%d%d",&s.dob.day,&s.dob.month,&s.dob.year);
    
} 