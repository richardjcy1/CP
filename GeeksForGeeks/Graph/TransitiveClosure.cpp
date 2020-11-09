#include <bits/stdc++.h>
using namespace std;
#define V 4

void printSolution(int reach[][V])
{
    printf("Following matrix is transitive closure of the given graph\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("%d ", reach[i][j]);
        }
        printf("\n");
    }
}

void transitiveClosure(int graph[][V])
{
    int reach[V][V], i, j, k;
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            reach[i][j] = graph[i][j];
        }
    }
    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }
    printSolution(reach);
}

int main()
{
    /* Let us create the following weighted graph
            10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
            3           */
    int graph[V][V] = { {1, 1, 0, 1},
                        {0, 1, 1, 0},
                        {0, 0, 1, 1},
                        {0, 0, 0, 1}
                      };

    // Print the solution
    transitiveClosure(graph);
    return 0;
}


