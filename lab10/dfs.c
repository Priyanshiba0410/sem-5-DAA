#include <stdio.h>

#define MAX 10

int visited[MAX];
int adj[MAX][MAX];
int n;

void DFS(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < n; i++) {
        if (adj[vertex][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main() {
    int edges, v1, v2, startVertex;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (v1 v2):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &v1, &v2);
        adj[v1][v2] = 1;
        adj[v2][v1] = 1; 
    }

    printf("Enter starting vertex: ");
    scanf("%d", &startVertex);

    printf("DFS Traversal: ");
    DFS(startVertex);

    return 0;
}
