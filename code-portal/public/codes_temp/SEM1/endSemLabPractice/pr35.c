#include <stdio.h>
struct Employee{
    long id;
    char name[100];
    long salary;
};
int main(){
    struct Employee e[3];
    for(int i=0;i<3;i++){
        printf("Details of employee %d\n",i+1);
        printf("ID = ");
        scanf("%ld",&e[i].id);
        printf("Name = ");
        scanf("%s",e[i].name);
        printf("Salary = ");
        scanf("%ld",&e[i].salary);
    }
    int max=0;
    for(int i=1;i<3;i++){
        if(e[i].salary>e[max].salary){
            max=i;
        }
    }
    printf("Employee %d has max salary!\n",max+1);
    printf("ID = %ld\n",e[max].id);
    printf("Name = %s\n",e[max].name);
    printf("Salary = %ld\n",e[max].salary);
    return 0;
}