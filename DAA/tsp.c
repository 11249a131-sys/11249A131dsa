#include <stdio.h>
#include <limits.h>
#define MAXN 15
#define INF INT_MAX
int n;
int d[MAXN][MAXN];
int dp[MAXN][1 << MAXN];
int g(int i, int S)
{
    if (S == 0)
        return d[i][0]; 
    if (dp[i][S] != -1) 
        return dp[i][S];

    int minCost = INF;
    int k;
    for ( k = 0; k < n; k++)
    {

        if (S & (1 << k))
        {
            int cost = d[i][k] + g(k, S & ~(1 << k));
            if (cost < minCost)
            {
                minCost = cost;
            }
        }
    }
    return dp[i][S] = minCost;
}

int main()
{
	int i, j, mask;
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for ( i = 0; i < n; i++)
        for ( j = 0; j < n; j++)
            scanf("%d", &d[i][j]);
    for ( i = 0; i < n; i++)
        for ( mask = 0; mask < (1 << n); mask++)
        {
            dp[i][mask] = -1;
        }

    int S = 0;
    for ( i = 1; i < n; i++)
        S |= (1 << i);

    int result = g(0, S);

    printf("Given Cost Matrix\n");
    for ( i = 0; i < n; i++)
    {
        
        printf("|");
        for (j = 0; j < n; j++)
            printf(" %d ", d[i][j]);
        printf("|\n");
    }
    printf("Minimum travelling cost: %d\n", result);

    return 0;
}
