#include <stdio.h>

struct Date{
    int dd,mm,yyyy;
};
struct Student{
    char name[50];
    int id;
    struct Date dob;
};
int main(){
    struct Student s[3];
    printf("Enter details:\n");
    for(int i=0; i<3; i++){
        printf("Student %d -\nName, ID, dob: ",i+1);
        scanf("%s%d%d%d%d",s[i].name,&s[i].id,&s[i].dob.dd,&s[i].dob.mm,&s[i].dob.yyyy);
    }
    printf("Displaying details :-\nName\tID\tDOB\n");
    for(int i=0; i<3; i++){
        printf("%s\t%d\t%d/%d/%d\n",s[i].name,s[i].id,s[i].dob.dd,s[i].dob.mm,s[i].dob.yyyy);
    }
    return 0;
}
