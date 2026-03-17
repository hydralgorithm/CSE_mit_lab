#include <stdio.h>
int main(){
    int y;
    scanf("%d",&y);
    if((y%4==0 && y%4!=100)||(y%400==0))
        printf("Leap year");
    else
        printf("Not leap year!");
}