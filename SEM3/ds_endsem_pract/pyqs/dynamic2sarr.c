#include <stdio.h>
#include <stdlib.h>
int main(){
    int n, **marks;
    printf("Enter number of students: ");
    scanf("%d",&n);
    marks = malloc(n*sizeof(int *));
    if(marks==NULL)
        return 1;
    for(int i=0; i<n; i++){
        *(marks+i) = malloc(3*sizeof(int));
    }
    for(int i=0; i<n;i++){
        for(int j=0; j<3; j++){
            scanf("%d",*(marks+i)+j);
        }
    }
    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=0; j<3; j++){
            sum+=*(*(marks+i)+j);
        }
        printf("Avg stud %d: %.2f\n",i+1, sum/3.0);
    }
    for(int i=0;i<n;i++)
        free(*(marks+i));
    free(marks);
    return 0;
}