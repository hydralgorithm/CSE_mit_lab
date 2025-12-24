#include <stdio.h>
struct Address{
    char street[100];
    char city[100];
    long zip;
};
struct Student{
    char name[100];
    long rollno;
    struct Address addr;
};
int main(){
    struct Student s;
    printf("Enter stud details:\n--------------------------\n");
    printf("Name: ");
    scanf("%s",s.name);
    printf("Roll number: ");
    scanf("%ld",&s.rollno);
    printf("Enter Address details:\n--------------------------\n");
    printf("Street: ");
    scanf("%s",s.addr.street);
    printf("City: ");
    scanf("%s",s.addr.city);
    printf("Pincode: ");
    scanf("%ld",&s.addr.zip);

    printf("Overall stud details:\n--------------------------\n");
    printf("Name: %s\n",s.name);
    printf("Roll number: %ld\n",s.rollno);
    printf("Street: %s\n",s.addr.street);
    printf("City: %s\n",s.addr.city);
    printf("Pincode: %ld\n",s.addr.zip);
    return 0;
}