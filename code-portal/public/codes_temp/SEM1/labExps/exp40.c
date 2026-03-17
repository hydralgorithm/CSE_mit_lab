#include <stdio.h>
struct address{
    char city[30];
    char street[75];
    long zip;
};
struct student{
    char name[50];
    long rollno;
    struct address addr;
};
int main(){
    struct student s;
    printf("Enter student name: ");
    scanf("%s",s.name);
    printf("Enter student roll number: ");
    scanf("%ld",&s.rollno);
    printf("Enter street: ");
    scanf("%s",s.addr.street);
    printf("Enter city: ");
    scanf("%s",s.addr.city);
    printf("Enter the ZIP code: ");
    scanf("%ld",&s.addr.zip);
    printf("Student details\n-------------------\n");
    printf("Name: %s\n",s.name);
    printf("Roll Number: %ld\n\n",s.rollno);
    printf("Address\n-----------------\n");
    printf("Street: %s\n",s.addr.street);
    printf("City: %s\n",s.addr.city);
    printf("ZIP code: %ld\n",s.addr.zip);
    return 0;
}