#include <stdio.h>
#define MAX 20
#define INF 999999

int main()
{
    int n, cost[MAX][MAX];
    int visited[MAX] = {0};
    int minCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            // Replace 0 with INF (except diagonal)
            if (cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }
    }

    visited[0] = 1; // Start from vertex 0
    int edges = 0;

    printf("\nEdges in MST:\n");

    while (edges < n - 1)
    {
        int min = INF, u = -1, v = -1;

        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u != -1 && v != -1)
        {
            printf("%d - %d : %d\n", u, v, min);
            minCost += min;
            visited[v] = 1;
            edges++;
        }
    }

    printf("Minimum cost = %d\n", minCost);

    return 0;
}
