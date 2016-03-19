#include "graphs.h"

struct graph {
    int node_count;
    int ** matrix;
};

void create_graph(Graph* input_graph , int node_count) {
    
    input_graph->matrix = calloc(node_count , sizeof(int*));
    for(int i = 0; i < node_count; i++) {
        input_graph->matrix[i] = calloc(node_count , sizeof(int));
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
    return input_graph->matrix[node1][node2] == 1;
}

void create_edge(Graph* input_graph , int node1 , int node2) {
    input_graph->matrix[node1][node2] = 1;
    input_graph->matrix[node2][node1] = 1;
}

void remove_edge(Graph* input_graph , int node1 , int node2) {
    input_graph->matrix[node1][node2] = 0;
    input_graph->matrix[node2][node1] = 0;
}