#include <stdlib.h>
#include "graphs.h"
#include <limits.h>
#define  bool int
#include <float.h>
void create_graph(Graph* input_graph , int node_count) {
    
    input_graph->matrix = calloc(node_count , sizeof(float*));
    for(int i = 0; i < node_count; i++) {
        input_graph->matrix[i] = calloc(node_count , sizeof(float));
    }
    input_graph->node_count = node_count;
}

void destroy_graph(Graph* input_graph) {
    for(int i = 0; i < input_graph->node_count; i++) {
        free(input_graph->matrix[i]);
    }
    free(input_graph->matrix);
    input_graph->node_count = 0;
}

int contains_edge(Graph* input_graph , int node1 , int node2) {
    return input_graph->matrix[node1][node2] > 0;
}

void create_edge(Graph* input_graph , int node1 , int node2, float weight) {
    input_graph->matrix[node1][node2] = weight;
    input_graph->matrix[node2][node1] = weight;
}

void remove_edge(Graph* input_graph , int node1 , int node2) {
    input_graph->matrix[node1][node2] = 0;
    input_graph->matrix[node2][node1] = 0;
}
/* Deph first search */
void dfs(Graph* g,int v,bool visited[]){
    
    float** matrix = g->matrix;
    visited[v] = 1;
    for(int i = 1; i <=g->node_count ; i++){
        if(matrix[v][i] > 0 && !visited[i]){
            dfs(g,i,visited);
        }
    }
        
}
 
int isConnected(Graph* graph,int visited[]){
    
	for(int i = 0 ; i <graph->node_count;i++)  {visited[i] = 0;}
    dfs(graph,1,visited);
    int count = 0;
     
    for (int i = 1; i <= graph->node_count; i++)  {
        if (visited[i])  
             count++;
    }
    return count == graph->node_count;
}

