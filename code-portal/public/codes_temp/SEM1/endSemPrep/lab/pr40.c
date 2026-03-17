#include <stdio.h>
struct Product{
    long id;
    char name[50];
    float price;
};
int main(){
    int i;
    struct Product p[2];
    struct Product *ptr;
    ptr = p;
    for(i=0;i<2;i++){
        printf("Product %d details:\n",i+1);
        printf("ID = ");
        scanf("%ld",&(ptr+i)->id);
        printf("Name = ");
        scanf("%s",(ptr+i)->name);
        printf("Price = ");
        scanf("%f",&(ptr+i)->price);
    }
    printf("\n________________________\n");
    printf("ID\tName\tPrice");
    printf("\n________________________\n");
    for(i=0;i<2;i++){
        printf("%ld\t%s\t%.2f\n",(ptr+i)->id,(ptr+i)->name,(ptr+i)->price);
    }
    return 0;
}