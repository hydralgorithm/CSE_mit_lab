#include <stdio.h>
#include <stdlib.h>
#define MAX 50
typedef struct node{
    int vertex;
    struct node *next;
} Node;
Node *graph[MAX];
int visited[MAX];
int n;
Node *createNode(int v){
    Node *temp = malloc(sizeof(Node));
    if(temp==NULL)
        exit(1);
    temp->vertex = v;
    temp->next = NULL;
    return temp;
}
Node *addEdge(int src, int des){
    Node *temp = createNode(des);
    temp->next = graph[src];
    graph[src] = temp;
    temp = createNode(src);
    temp->next = graph[des];
    graph[des] = temp;
}
void dfs(int v){
    Node *temp;
    visited[v] = 1;
    printf("%d ",v);
    for(temp=graph[v];temp!=NULL;temp=temp->next){
        if(!visited[temp->vertex])
            dfs(temp->vertex);
    }
}