#include <stdio.h>
#include <stdlib.h>
#define MAX 50
typedef struct node{
    int vertex;
    struct node *next;
} Node;
Node *graph[MAX];
int n;
Node *createNode(int v){
    Node *temp = malloc(sizeof(Node));
    temp->vertex = v;
    temp->next = NULL;
    return temp;
}
void addEdge(int src, int dest){
    Node *temp;
    
    temp = createNode(dest);
    temp->next = graph[src];
    graph[src] = temp;

    temp = createNode(src);
    temp->next = graph[dest];
    graph[dest] = temp;
}
void displayGraph(){
    for(int i=0; i<n; i++){
        Node *temp = graph[i];
        printf("%d: ",i);
        while (temp != NULL){
            printf("%d -> ",temp->vertex);
            temp= temp->next;
        }
        printf("NULL\n");
    }
}
int main() {
    int edges, src, dest;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        graph[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }

    displayGraph();
    return 0;
}