#include <stdlib.h>
#include "graphs.h"
#include <limits.h>
#define  bool int
#include <float.h>
int minDistance(float dist[], bool sptSet[],int V)
{
   
   int min = INT_MAX, min_index;
 
   for (int v = 0; v < V; v++)
     if (sptSet[v] == 0 && dist[v] <= min)
         min = dist[v], min_index = v;
 
   return min_index;
}

void printPath(float parent[], int j){
    // if j is the src itself
    if (parent[j]==-1)
        return;
 
    printPath(parent, parent[j]);
 
    printf("%d ", j);
}
float printSolution(float dist[], int n, float parent[],int src){
    
    printf("Edge            Distance         Path");
    for (int i = 1; i < n; i++){
        if(dist[i] != FLT_MAX){
            printf("\n%d -> %d          %f         ", src, i, dist[i]);
        printPath(parent, i);
            
        }
    }
}
 /* Dijkstra’s algorithm for calculating all the shortest path routes given a src node */
void shortestPathList(Graph* graph, int src){
    float** matrix = graph->matrix;
    int node_count = graph->node_count;
    float dist[node_count];  // Output array  
 
    // "boolean" array to store whether a vertex i is included in the shortest path route
    // path tree or shortest distance from src to i is finalized
    bool sptSet[node_count];
 
    // storing the path tree
    float parent[node_count];
 
 
    for (int i = 0; i < node_count; i++)
    {
        parent[0] = -1;
        dist[i] = FLT_MAX;
        sptSet[i] = 0;
    }
 
    
    dist[src] = 0;
 
   
    for (int count = 0; count < (node_count)-1; count++)
    {
       
        int u = minDistance(dist, sptSet,node_count);
 
        
        sptSet[u] = 1;
 
     
        for (int v = 0; v < node_count; v++)
 
            
            if (!sptSet[v] && matrix[u][v] &&
                dist[u] + matrix[u][v] < dist[v])
            {
                parent[v]  = u;
                dist[v] = dist[u] + matrix[u][v];
            }  
    }
 
    printSolution(dist, node_count, parent,src);
}
