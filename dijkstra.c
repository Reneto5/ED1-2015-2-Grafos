#include <stdio.h>
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
void printSolution(float dist[], int n, float parent[],int src){
    
    printf("Aresta          Distancia        Caminho");
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
void printSingleSolution(float dist[], int n, float parent[],int src,int dest){
    if(dist[dest] != FLT_MAX){ 
         printf("Caminho encontrado!\n\n");
        printf("Aresta          Distancia        Caminho");
        printf("\n%d -> %d          %f         ", src, dest, dist[dest]);
        printPath(parent, dest);
    }
    else{
        printf("Nao ha caminho entre os vertices informados.\n\n");
    }
    
    
}

void isThereAPath(Graph* graph, int src, int dest){
    float** matrix = graph->matrix;
    int node_count = graph->node_count;
    float* dist = malloc(node_count * sizeof(float));  // Output array  
 
    // "boolean" array to store whether a vertex i is included in the shortest path route
    // path tree or shortest distance from src to i is finalized
    bool* sptSet = malloc(node_count * sizeof(bool));
 
    // storing the path tree
    float* parent = malloc(node_count * sizeof(float));
 
 
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
 
    printSingleSolution(dist, node_count, parent,src,dest);
}
