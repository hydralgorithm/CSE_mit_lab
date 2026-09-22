#include <stdio.h>

struct Student{
    int USN;
    char name[100];
    int sem;
    float cgpa;
};
int main(){
    struct Student s[5];
    for(int i=0; i<5; i++){
        printf("Stud %d - USN\tname\tsem\tcgpa:\n",(i+1));
        scanf("%d%s%d%f",&s[i].USN,s[i].name,&s[i].sem,&s[i].cgpa);
    }
    for(int i=0; i<5; i++){
        if(s[i].cgpa > 8.5){
            printf("Stud %d: %d %s %d %.2f\n",(i+1),s[i].USN,s[i].name,s[i].sem,s[i].cgpa);
        }
    }
    return 0;
}