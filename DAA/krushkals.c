#include <stdio.h>
#include <stdlib.h>

#define V 5
#define INF 999999

// Function to find vertex with minimum key value
int minKey(int key[], int visited[])
{
    int min = INF;
    int min_index = -1;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && key[i] < min)
        {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

// Function to print MST
void printPrimMST(int parent[], int graph[V][V])
{
    printf("\nPrim's MST:\n");
    printf("Edge \tWeight\n");

    int total = 0;
    for (int i = 1; i < V; i++)
    {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        total += graph[i][parent[i]];
    }

    printf("Total Cost = %d\n", total);
}

// Prim's Algorithm
void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    int visited[V];

    // Initialize
    for (int i = 0; i < V; i++)
    {
        key[i] = INF;
        visited[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    // Build MST
    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++)
        {
            // Check edge exists, not visited, and smaller weight
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printPrimMST(parent, graph);
}

int main()
{
    int graph[V][V] = {
        {0, 2, 3, 0, 0},
        {2, 0, 5, 3, 0},
        {3, 5, 0, 0, 4},
        {0, 3, 0, 0, 2},
        {0, 0, 4, 2, 0}
    };

    primMST(graph);

    return 0;
}
