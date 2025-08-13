#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 6 

int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int graph[V][V]) {
    int totalCost = 0;
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
        totalCost += graph[i][parent[i]];
    }
    printf("Total Minimum Cost = %d\n", totalCost);
}

void primsMST(int graph[V][V]) {
    int parent[V];
    int key[V];        
    bool mstSet[V];    

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;        
    parent[0] = -1;    

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);  
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph);
}

int main() {
    int graph[V][V] = {
        {0, 9, 22, 0, 11, 12},
        {9, 0, 16, 0, 14, 8},
        {22, 16, 0, 15, 18, 0},
        {0, 0, 15, 0, 3, 0},
        {11, 14, 18, 3, 0, 0},
        {12, 8, 0, 0, 0, 0},
    };

    primsMST(graph);

    return 0;
}
