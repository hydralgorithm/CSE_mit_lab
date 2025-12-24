#include <stdio.h>
struct cricket{
    char name[50];
    char team[50];
    float batavg;
};
int main(){
    struct cricket c[10];
    int n,i,j;
    printf("Enter no of players: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Player %d :\n",i+1);
        printf("Name: ");
        scanf("%s",c[i].name);
        printf("Team Name: ");
        scanf("%s",c[i].team);
        printf("Batting avg: ");
        scanf("%f",&c[i].batavg);
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(c[j].batavg<c[j+1].batavg){
                struct cricket temp = c[j];
                c[j]=c[j+1];
                c[j+1]=temp;
            }
        }
    }
    
    printf("\n=== Players sorted by batting average (descending) ===\n");
    printf("Name\t\tTeam\t\tBatting Avg\n");
    printf("------------------------------------------------\n");
    for(i=0;i<n;i++){
        printf("%-15s\t%-15s\t%.2f\n", c[i].name, c[i].team, c[i].batavg);
    }
    
    return 0;
}