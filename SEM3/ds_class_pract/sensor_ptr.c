#include <stdio.h>
#include <stdlib.h>

int main(){
    int *sens = (int *)malloc(5*sizeof(int));
    for(int i=0; i<5; i++){
        printf("Sensor %d: ",(i+1));
        scanf("%d",(sens+i));
    }
    for(int i=0; i<5; i++){
        printf("Sensor %d: %d\n",(i+1),*(sens+i));
    }
    free(sens);
    return 0;   
}