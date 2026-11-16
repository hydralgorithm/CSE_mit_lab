#include <stdio.h>
typedef int element;
element memory[20];
int top[4], boundary[4];

void initialize(){
    for(int i=0; i<4; i++){
        boundary[i] = i*5;
        top[i] = boundary[i]-1;
    }
}
void push(int i, element x){
    if(top[i]==boundary[i]+4)
        return;
    memory[++top[i]] = x;
}
element pop(int i){
    if(top[i]<boundary[i])
        return -1;
    return memory[top[i]--];
}