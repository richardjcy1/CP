#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int src, dest, weight;
};

struct Graph
{
    int V, E;
    Edge* edge;
};

Graph* createGraph(int V, int E)
{
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;

    graph->edge = new Edge[E];
    
    return graph;
}

struct subset
{
    int parent;
    int rank;
};

int fi(subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = fi(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void uni(subset subsets[], int x, int y)
{
    int xroot = fi(subsets, x);
    int yroot = fi(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
    {
        subsets[xroot].parent = yroot;
    }
    else if (subsets[xroot].rank > subsets[yroot].rank)
    {
        subsets[yroot].parent = xroot;
    }
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int myComp(const void* a, const void* b)
{
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight > b1->weight;
}

void KruskalMST(Graph* graph)
{
    int V = graph->V;
    Edge result[V];
    int e = 0, i = 0;

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);

    subset* subsets = new subset[(V * sizeof(subset))];

    for (int v = 0; v < V; v++)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph->E)
    {
        Edge next_edge = graph->edge[i++];

        int x = fi(subsets, next_edge.src);
        int y = fi(subsets, next_edge.dest);

        if (x != y)
        {
            result[e++] = next_edge;
            uni(subsets, x, y);
        }
    }

    cout << "Following are the dges in the constructed MST\n";
    for (i = 0; i < e; i++)
    {
        cout << result[i].src << " -- " << result[i].dest << " == " << result[i].weight << endl;
    }
}

int main()  
{  
    /* Let us create following weighted graph  
            10  
        0--------1  
        | \ |  
    6| 5\ |15  
        | \ |  
        2--------3  
            4 */
    int V = 4; // Number of vertices in graph  
    int E = 5; // Number of edges in graph  
    Graph* graph = createGraph(V, E);  
  
  
    // add edge 0-1  
    graph->edge[0].src = 0;  
    graph->edge[0].dest = 1;  
    graph->edge[0].weight = 10;  
  
    // add edge 0-2  
    graph->edge[1].src = 0;  
    graph->edge[1].dest = 2;  
    graph->edge[1].weight = 6;  
  
    // add edge 0-3  
    graph->edge[2].src = 0;  
    graph->edge[2].dest = 3;  
    graph->edge[2].weight = 5;  
  
    // add edge 1-3  
    graph->edge[3].src = 1;  
    graph->edge[3].dest = 3;  
    graph->edge[3].weight = 15;  
  
    // add edge 2-3  
    graph->edge[4].src = 2;  
    graph->edge[4].dest = 3;  
    graph->edge[4].weight = 4;  
  
    KruskalMST(graph);  
  
    return 0;  
}  