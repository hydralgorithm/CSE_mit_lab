//4 COLUMNS AND 16 ROWS CHECK IF WINDOW SEAT?
#include <stdio.h>
int main()
{
    int n,i,j,flag=1;
    scanf("%d",&n);
    for(i=0;i<16;i++){
        if(n==4*i+1 || n==4*i+4){
            flag=0;
            break;
        }
    }
    if(flag==0)
        printf("Window seat");
    else
        printf("Not window seat");
}