#include <stdio.h>

#define MAX 10

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;
int n; // number of vertices

void enqueue(int vertex) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = vertex;
}

int dequeue() {
    if (front == -1) return -1;
    int vertex = queue[front++];
    if (front > rear) {
        front = rear = -1;
    }
    return vertex;
}

void BFS(int startVertex) {
    enqueue(startVertex);
    visited[startVertex] = 1;

    while (front != -1) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);

        for (int i = 0; i < n; i++) {
            if (adj[currentVertex][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int edges, v1, v2, startVertex;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency matrix and visited array
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
        adj[v2][v1] = 1; // For undirected graph
    }

    printf("Enter starting vertex: ");
    scanf("%d", &startVertex);

    printf("BFS Traversal: ");
    BFS(startVertex);

    return 0;
}
