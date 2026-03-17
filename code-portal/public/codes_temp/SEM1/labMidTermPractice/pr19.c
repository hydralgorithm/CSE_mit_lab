#include <stdio.h>
int main(){
    int i,j,n;
    scanf("%d",&n);
    printf("sin(x) = ");
    for(i=0;i<n;i++){
        int power=2*i+1;
        if(i>0){
            if(i%2==0)
                printf(" + ");
            else
                printf(" - ");
        }
        printf("x^%d/%d!",power,power);
    }
    return 0;
}