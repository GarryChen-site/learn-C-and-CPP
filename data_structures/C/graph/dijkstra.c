
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Structure for sorting a graph
struct Graph
{
    int vertexNum;
    int **edges;
};

// Constructs a graph with V vertices and E edges
void createGraph(struct Graph *G, int V)
{
    G->vertexNum = V;
    G->edges = (int**)malloc(V * sizeof(int *));
    for(int i=0; i< V; i++)
    {
        G->edges[i] = (int*)malloc(V * sizeof(int));
        for(int j=0; j<V;j++)
        {
            G->edges[i][j] = INT_MAX;
        }
        G->edges[i][i] = 0;
    }
}

// Adds the given edge to the graph
void addEdge(struct Graph *G, int src, int dst, int weight)
{
    G->edges[src][dst] = weight;
}

// Utility function to find minimum distance vertex in mdist
int minDistance(int mdist[], int vset[], int V)
{
    int minVal = INT_MAX;
    int minInd;
    for(int i=0; i<V; i++)
    {
        if(vset[i] == 0 && mdist[i]<minVal)
        {
            minVal = mdist[i];
            minInd = i;
        }
    }

    return minInd;
}

// The main function that finds the shortest path from given source
// to all other vertices using Dijkstra's Algorithm. It doesn't work on negative weights
void Dijkstra(struct Graph *graph, int src)
{
    int V = graph -> vertexNum;
    int mdist[V]; // Stores updated distances to vertex
    int vset[V]; // vset[i] is true if the vertex i included in the shortest path tree

    // Initialise mdist and vset. Set distance of source as zero
    for(int i=0; i<V; i++)
    {
        mdist[i] = INT_MAX;
        vset[i] = 0;
    }

    mdist[src] = 0;

    // iterate to find shortest path
    for(int count = 0; count < V-1; count++)
    {
        int u = minDistance(mdist,vset,V);
        vset[u] = 1;

        for(int v = 0; v < V; v++)
        {
            if(!vset[v] && graph->edges[u][v] != INT_MAX 
            && mdist[u] + graph->edges[u][v] < mdist[v])
            {
                mdist[v] = mdist[u] + graph->edges[u][v];
            }
        }
    }

    return;
}