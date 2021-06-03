
#include "graph.h"
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct GraphRep
{
    int **edges; // adjacency matrix
    int nV;      // #vertices
    int nE;      // #edges
} GraphRep;

Graph newGraph(int V)
{
    assert(V >=0);
    int i;

    Graph g = malloc(sizeof(GraphRep));
    assert(g != NULL);
    g->nV = V;
    g->nE = 0;

    // allocate memory for each row
    g->edges = malloc(V * sizeof(int *));
    assert(g->edges !=NULL);
    // allocate memory for each column and initialise with 0
    for(int i=0; i < V; i++)
    {
        g->edges[i] = calloc(V,sizeof(int));
        assert(g->edges[i] != NULL);
    }

    return g;

}