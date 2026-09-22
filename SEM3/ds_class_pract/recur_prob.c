#include <stdio.h>

int Amount(int n,int initial, int interest){
    if(n==0)
        return initial;
    return Amount(n-1, initial, interest)+interest;
}
int main(){
    printf("Final Amount: %d",Amount(5,10000,500));
    return 0;
}