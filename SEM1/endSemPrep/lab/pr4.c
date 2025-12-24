#include <stdio.h>
int main(){
    printf("Size of int: %d bytes.\n",sizeof(int));
    printf("Size of char: %d bytes.\n",sizeof(char));
    printf("Size of float: %d bytes.\n",sizeof(float));
    printf("Size of double: %d bytes.\n",sizeof(double));
    printf("Size of long int: %d bytes.\n",sizeof(long int));
    printf("Size of long double: %d bytes.\n",sizeof(long double));
    return 0;
}