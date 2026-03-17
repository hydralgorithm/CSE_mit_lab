#include <stdio.h>
struct product{
    long id;
    char name[50];
    float price;
};
int main(){
    int n;
    printf("Enter number of products: ");
    scanf("%d",&n);
    struct product p[n];
    struct product *ptr;
    ptr=p;
    for(int i=0;i<n;i++){
        printf("Enter details of the product %d\n",i+1);
        printf("Product ID: ");
        scanf("%ld",&(ptr+i)->id);
        printf("Product name: ");
        scanf("%s",(ptr+i)->name);
        printf("Product price: ");
        scanf("%f",&(ptr+i)->price);
    }
    printf("\n_______________________________\n");
    printf("ID\tName\tPrice");
    printf("\n_______________________________\n");
    for(int i=0;i<n;i++){
    printf("%ld\t%s\t%.2f\n",(ptr+i)->id,(ptr+i)->name,(ptr+i)->price);
    }
    return 0;
}