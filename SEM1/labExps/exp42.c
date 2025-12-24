#include <stdio.h>
struct Player{
    char name[50];
    char team[50];
    float battingAvg;
};
int main(){
    int i,n,j;
    printf("Enter number of players: ");
    scanf("%d",&n);
    struct Player p[n];
    for(i=0;i<n;i++){
        printf("\nEnter details of player %d\n",i+1);
        printf("Player name: ");
        scanf("%s",p[i].name);
        printf("Team name: ");
        scanf("%s",p[i].team);
        printf("Batting Average: ");
        scanf("%f",&p[i].battingAvg);
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(p[j].battingAvg<p[j+1].battingAvg){
                struct Player temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
    printf("\n\nPlayers sorted by batting average:\n");
    printf("%-30s %-30s %s\n","Player name","Team name","Batting Average");
    printf("------------------------------------------------------\n");
    for(i=0;i<n;i++){
        printf("%-30s %-30s %.2f\n",p[i].name,p[i].team,p[i].battingAvg);
    }
    return 0;
}